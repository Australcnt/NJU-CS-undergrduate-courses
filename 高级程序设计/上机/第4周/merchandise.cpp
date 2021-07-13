#include "merchandise.h"
#include "merchandise_list.h"
#include "user.h"

using namespace std;

Merchandise::Merchandise(const char* name, int price)
{
	good_name = new char[100];
	strcpy(good_name , name);
	good_price = price;
}

const char* Merchandise::GetMerchandiseName()
{
	return good_name;
}

int Merchandise::GetMerchandisePrice()
{
	return good_price;
}

/*int main()
{
	Merchandise mer_pen = Merchandise("pen", 2); // 创建⼀个Merchandise对象，名为pen，价格为2元
	Merchandise mer_apple = Merchandise("apple", 3); // 创建⼀个Merchandise对象，名为apple，价格为3元
	mer_pen.GetMerchandiseName(); //返回商品名
	mer_pen.GetMerchandisePrice(); //返回商品价格


	MerchandiseList merchandise_list; // 创建⼀个merchandise_list对象
	merchandise_list.AddRecord(&mer_pen, 8); // 在merchandise_list中添加⼀条记录(&mer_pen, 8)
	merchandise_list.ModifyRecord(&mer_pen, 7); // 修改merchandise_list中的项(&mer_pen, 8)为(&mer_pen, 7)
	merchandise_list.FindRecord(&mer_pen); // 查找&mer_pen所在的项，并返回7
	merchandise_list.DeleteRecord(&mer_pen); // 成功删除mer_pen，并返回true
	merchandise_list.DeleteRecord(&mer_apple); // 因为mer_apple不在merchandise_list中，删除失败并返回false
	
	
	User user_Tom = User("Tom"); // 创建一个User对象，用户名为Tom
	user_Tom.BrowseMerchandise(&mer_pen); // 浏览商品pen⼀次
	user_Tom.GetBrowseHistory(); // 返回用户Tom的浏览记录
	user_Tom.BuyMerchandise(&mer_apple, 6); // 购买6个apple
	user_Tom.GetBuyHistory(); // 返回用户Tom的购买记录
	user_Tom.BuyMerchandise(&mer_apple, 2); // 再次购买2个苹果
	user_Tom.GetBuyHistory(); // 返回再次购买后的购买记录


	return 0;
}*/