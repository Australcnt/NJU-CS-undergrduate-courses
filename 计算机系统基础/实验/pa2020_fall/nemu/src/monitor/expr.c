#include "nemu.h"
#include "cpu/cpu.h"
#include "cpu/reg.h"
#include "memory/memory.h"

#include <stdlib.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <sys/types.h>
#include <regex.h>

extern uint32_t look_up_symtab(char* sym, bool* success);

enum
{
    /* TODO: Add more token types */
    
	NOTYPE = 256,
	HEX,
	NUM,
	REG,
	SYMB,
    EQ,
    NEQ,
    AND,
	OR,
	NOT,
	NEG,
	DEREF
};

static struct rule
{
	char *regex;
	int token_type;
} rules[] = {

	/* TODO: Add more rules.
	 * Pay attention to the precedence level of different rules.
	 */

	{" +", NOTYPE}, // white space
    {"0[xX][0-9a-fA-F]{1,29}", HEX},
    {"[0-9]{1,31}", NUM}, // dec
    {"\\$e[acdb]x|\\$e[sbi]p|\\$e[sd]i", REG},
    {"[a-zA-Z]+[a-zA-Z0-9_]{0,30}", SYMB},
    {"\\+", '+'},
    {"-", '-'},
    {"\\*", '*'},
    {"/", '/'},
    {"\\(", '('},
    {"\\)", ')'},
	{"==", EQ},
	{"!=", NEQ},
	{"&&", AND},
	{"\\|\\|", OR},
	{"!", NOT}
	
};

#define NR_REGEX (sizeof(rules) / sizeof(rules[0]))

static regex_t re[NR_REGEX];

/* Rules are used for more times.
 * Therefore we compile them only once before any usage.
 */
void init_regex()
{
	int i;
	char error_msg[128];
	int ret;

	for (i = 0; i < NR_REGEX; i++)
	{
		ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
		if (ret != 0)
		{
			regerror(ret, &re[i], error_msg, 128);
			assert(ret != 0);
		}
	}
}

typedef struct token
{
	int type;
	char str[32];
} Token;

Token tokens[32];
int nr_token;

static bool make_token(char *e)
{
	int position = 0;
	int i;
	regmatch_t pmatch;

	nr_token = 0;

	while (e[position] != '\0')
	{
		/* Try all rules one by one. */
		for (i = 0; i < NR_REGEX; i++)
		{
			if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
			{
				char *substr_start = e + position;
				int substr_len = pmatch.rm_eo;

				//printf("match regex[%d] at position %d with len %d: %.*s", i, position, substr_len, substr_len, substr_start);
				position += substr_len;

				/* TODO: Now a new token is recognized with rules[i]. 
				 * Add codes to perform some actions with this token.
				 */

				int j = 0;
				switch (rules[i].token_type)
				{
				    case NOTYPE: 
				        break;
				    case HEX:
				    case NUM:
				    case REG:
				    case SYMB:
				        for(j = 0; j < substr_len; j++)
				            tokens[nr_token].str[j] = substr_start[j];
				        tokens[nr_token].str[j] = '\0';
				        tokens[nr_token].type = rules[i].token_type;
					    nr_token++;
					    break;
				    default:
					    tokens[nr_token].type = rules[i].token_type;
					    nr_token++;
				}
				break;
			}
		}

		if (i == NR_REGEX)
		{
			printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
			return false;
		}
	}

	return true;
}

bool check_parentheses(int p, int q, bool* success)
{
    int parentheses_count = 0;
    if(tokens[p].type != '(' || tokens[q].type != ')')
        return false;
    for(int pos = p; pos <= q; pos++)
    {
        if(tokens[pos].type == '(')
            parentheses_count++;
        else if(tokens[pos].type == ')')
            parentheses_count--;
        if(parentheses_count < 0 || (parentheses_count == 0 && pos != q))
            *success = false;
    }
    if(parentheses_count != 0)
        *success = false;
    return true;
}

bool check_operator(int pos)
{
    if(tokens[pos].type == '+' || tokens[pos].type == '-' || tokens[pos].type == '*' || tokens[pos].type == '/' || tokens[pos].type == EQ || tokens[pos].type == NEQ || tokens[pos].type == AND || tokens[pos].type == OR || tokens[pos].type == NOT || tokens[pos].type == NEG || tokens[pos].type == DEREF)
        return true;
    else
        return false;
}

int priority(int pos)
{
    if(tokens[pos].type == NOT || tokens[pos].type == NEG || tokens[pos].type == DEREF)
        return 1;
    else if(tokens[pos].type == '*' || tokens[pos].type == '/')
        return 2;
    else if(tokens[pos].type == '+' || tokens[pos].type == '-')
        return 3;
    else if(tokens[pos].type == EQ || tokens[pos].type == NEQ)
        return 4;
    else if(tokens[pos].type == AND)
        return 5;
    else if(tokens[pos].type == OR)
        return 6;
    else
        return 0;
}

int get_dominant_operator(int p, int q)
{
    int dominant_pos = -1;
    int parentheses_count = 0;
    for(int i = p; i <= q; i++)
    {
        if(tokens[i].type == '(')
            parentheses_count++;
        else if(tokens[i].type == ')')
            parentheses_count--;
        if(!check_operator(i))
            continue;
        if((dominant_pos == -1 || priority(i) >= priority(dominant_pos)) && parentheses_count == 0)
            dominant_pos = i;
    }
    return dominant_pos;
}

uint32_t eval(int p, int q, bool* success) 
{
    //printf("\n%d\n%d\n", p, q);
    if(p > q) 
    {
        /* Bad expression */
        *success = false;
        return 0;
    }
    else if(p == q) 
    { 
        /* Single token.
         * For now this token should be a number. 
         * Return the value of the number.
         */ 
        uint32_t res = 0;
        if(tokens[p].type == NUM)
        {
            sscanf(tokens[p].str, "%d", &res);
            return res;
        }
        else if(tokens[p].type == HEX)
        {
            sscanf(tokens[p].str, "%x", &res);
            return res;
        }
        else if(tokens[p].type == REG)
        {
            if(strcmp(tokens[p].str, "$eax") == 0)
                return cpu.eax;
            else if(strcmp(tokens[p].str, "$ecx") == 0)
                return cpu.ecx;
            else if(strcmp(tokens[p].str, "$edx") == 0)
                return cpu.edx;
            else if(strcmp(tokens[p].str, "$ebx") == 0)
                return cpu.ebx;
            else if(strcmp(tokens[p].str, "$esp") == 0)
                return cpu.esp;
            else if(strcmp(tokens[p].str, "$ebp") == 0)
                return cpu.ebp;
            else if(strcmp(tokens[p].str, "$esi") == 0)
                return cpu.esi;
            else if(strcmp(tokens[p].str, "$edi") == 0)
                return cpu.edi;
            else if(strcmp(tokens[p].str, "$eip") == 0)
                return cpu.eip;
            else
                return 0;
        }
        else
        {
            return look_up_symtab(tokens[p].str, success);
        }
    }
    else if(check_parentheses(p, q, success) == true) 
    {
        /* The expression is surrounded by a matched pair of parentheses. 
         * If that is the case, just throw away the parentheses.
         */
        return eval(p + 1, q - 1, success); 
    }
    else 
    {
        /* We should do more things here. */
        uint32_t val1 = 0, val2 = 0;
        int op = get_dominant_operator(p, q);
        int op_type = tokens[op].type;
        //printf("\nop = %d\n", op);
        if(op_type != NEG && op_type != DEREF && op_type != NOT)
            val1 = eval(p, op - 1, success);
        val2 = eval(op + 1, q, success);
        switch(op_type) 
        {
            case '+': return val1 + val2; break;
            case '-': return val1 - val2; break;
            case '*': return val1 * val2; break;
            case '/': return val1 / val2; break;
            case EQ: return val1 == val2; break;
            case NEQ: return val1 != val2; break;
            case AND: return val1 && val2; break;
            case OR: return val1 || val2; break;
            case NOT: return !val2; break;
            case NEG: return -val2; break;
            case DEREF: return vaddr_read(val2, SREG_CS, 4); break;
            default: *success = false; return 0;
        }
    }
}

uint32_t expr(char *e, bool *success)
{
    *success = true;
	if (!make_token(e))
	{
		*success = false;
		return 0;
	}
    /* TODO: Implement code to evaluate the expression. */
    for(int i = 0; i < nr_token; i++)
    {
        if(i == 0 || (tokens[i - 1].type != NUM && tokens[i - 1].type != HEX && tokens[i - 1].type != REG && tokens[i - 1].type != SYMB)) 
        {
            if(tokens[i].type == '*')
                tokens[i].type = DEREF;
            else if(tokens[i].type == '-')
                tokens[i].type = NEG;
        }
    }
    
	//printf("\nPlease implement expr at expr.c\n");
	//fflush(stdout);
	//assert(0);

    uint32_t res = 0;
    res = eval(0, nr_token - 1, success);
	return res;
}
