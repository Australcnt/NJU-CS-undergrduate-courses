#include "merchandise.h"
#include "merchandise_list.h"
#include "user.h"


User::User(const char* user_name)
{
	users_name = new char[100];
	strcpy(users_name, user_name);
}

void User::BrowseMerchandise(Merchandise* merchandise)
{
	browse.AddRecord(merchandise,1);
}

MerchandiseList* User::GetBrowseHistory()
{
	return &browse;
}

void User::BuyMerchandise(Merchandise* merchandise, int number)
{
	perchase.AddRecord(merchandise, number);
}

MerchandiseList* User::GetBuyHistory()
{
	return &perchase;
}

/*int main()
{
	User user_Tom = User("Tom"); // 创建⼀个User对象，⽤户名为Tom

	user_Tom.BrowseMerchandise(&mer_pen); // 浏览商品pen⼀次

	user_Tom.GetBrowseHistory(); // 返回⽤户Tom的浏览记录

	user_Tom.BuyMerchandise(&mer_apple, 6); // 购买6个apple

	user_Tom.GetBuyHistory(); // 返回⽤户Tom的购买记录

	user_Tom.BuyMerchandise(&mer_apple, 2) // 再次购买2个苹果

	user_Tom.GetBuyHistory(); // 返回再次购买后的购买记录
	return 0;
}*/