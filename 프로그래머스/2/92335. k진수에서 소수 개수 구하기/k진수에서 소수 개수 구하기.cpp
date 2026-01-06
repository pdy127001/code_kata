#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long num)
{
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (long long i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

string toBaseK(long long n, int k)
{
    string result = "";
    while (n > 0)
    {
        result = char('0' + (n % k)) + result;
        n /= k;
    }
    return result;
}

int solution(int n, int k)
{
    string baseK = toBaseK(n, k);
    int answer = 0;

    string temp = "";
    for (char c : baseK)
    {
        if (c == '0')
        {
            if (!temp.empty())
            {
                long long val = stoll(temp);
                if (isPrime(val))
                    answer++;
                temp.clear();
            }
        }
        else
        {
            temp += c;
        }
    }

    if (!temp.empty())
    {
        long long val = stoll(temp);
        if (isPrime(val))
            answer++;
    }

    return answer;
}