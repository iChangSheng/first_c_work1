#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 学生账户结构体
struct Account
{
    int id;
    double balance;
};

// 账户充值
void recharge(Account& acc, double money)
{
    if (money < 0)
    {
        throw "充值金额不能为负数！";
    }
    acc.balance += money;
}

// 账户消费
void consume(Account& acc, double money, string item)
{
    if (money < 0)
    {
        throw "消费金额不能为负数！";
    }
    if (money > acc.balance)
    {
        throw "余额不足，无法消费！";
    }
    acc.balance -= money;
    cout << "消费项目：" << item << "，消费金额：" << fixed << setprecision(2) << money << " 元" << endl;
}

// 录入账户信息（带异常校验：余额不能为负）
void inputAccount(Account& acc)
{
    cout << "请输入账户ID：";
    cin >> acc.id;
    cout << "请输入账户初始余额：";
    cin >> acc.balance;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        throw "输入数据非法，不是数字！";
    }
    if (acc.balance < 0)
    {
        throw "账户初始余额不能为负数！";
    }
}

// 输出单个账户信息
void showAccount(const Account& acc)
{
    cout << "账户ID：" << acc.id << "，当前余额：" << fixed << setprecision(2) << acc.balance << " 元" << endl;
}

// 余额元转分
long long yuanToFen(double yuan)
{
    return static_cast<long long>(yuan * 100 + 0.5);
}

// 打印全部账户报表（对齐、保留两位小数）
void printReport(Account* arr, int n)
{
    cout << "\n==================== 全部账户报表 ====================" << endl;
    cout << left << setw(10) << "账户ID" << setw(15) << "余额(元)" << setw(15) << "余额(分)" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << arr[i].id
             << setw(15) << arr[i].balance
             << setw(15) << yuanToFen(arr[i].balance) << endl;
    }
    cout << "======================================================" << endl;
}

int main()
{
    cout << "==================== 学生一卡通系统 ====================" << endl;
    int stuNum;
    cout << "请输入学生数量：";
    cin >> stuNum;

    Account* accArray = nullptr;
    try
    {
        // 动态分配内存，new失败会抛出bad_alloc异常
        accArray = new Account[stuNum];
    }
    catch (const bad_alloc& e)
    {
        cerr << "内存申请失败：" << e.what() << endl;
        return 1;
    }

    // 循环录入账户，异常时重试
    for (int i = 0; i < stuNum; i++)
    {
        bool ok = false;
        while (!ok)
        {
            try
            {
                cout << "\n----- 录入第 " << i + 1 << " 个账户 -----" << endl;
                inputAccount(accArray[i]);
                ok = true;
            }
            catch (const char* errMsg)
            {
                cerr << "【录入异常】" << errMsg << "，请重新输入！" << endl;
            }
        }
    }

    // 模块8要求：第一个账户充值100元，消费8.5元，项目：食堂午餐
    try
    {
        cout << "\n===== 对第一个账户进行充值与消费操作 =====" << endl;
        recharge(accArray[0], 100.0);
        consume(accArray[0], 8.5, "食堂午餐");

        // 显示账户ID和余额
        showAccount(accArray[0]);
        // 余额换算成分输出
        long long fen = yuanToFen(accArray[0].balance);
        cout << "第一个账户余额换算为分：" << fen << " 分" << endl;
    }
    catch (const char* errMsg)
    {
        cerr << "【充值消费异常】" << errMsg << endl;
    }

    // 输出全部账户报表
    printReport(accArray, stuNum);

    // 释放动态内存
    delete[] accArray;
    accArray = nullptr;

    cout << "\n程序结束，内存已释放！" << endl;
    return 0;
}

