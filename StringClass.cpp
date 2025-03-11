#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cassert>

using std::cout;
using std::endl;

namespace vss
{
    class string
    {
        private:
            char* p_str;
            int N;

        public:
            string():p_str(0),N(0){}

            string(char* _s)
            {
                int L  = strlen(_s);
                p_str = (char*)malloc(L+1);
                assert(p_str);
                strncpy(p_str, _s, L+1);
                N = L;
            }

            //copy constructor
            string(string &rhs_str)
            {
                    N = rhs_str.N;
                    p_str = (char*)malloc(N+1);
                    strncpy(p_str, rhs_str.p_str, N+1);
            }

            friend std::ostream& operator<<(std::ostream& os, string& s)    
            {
                if(s.p_str)
                    printf("%s", s.p_str);
                return os;
            }

            ~string(){
                if(p_str)
                {
                    cout<<"Memory of string is freed"<<endl;
                    free(p_str);
                    p_str = 0;
                }
            }
    };    
}


int main(void)
{
    vss::string s1;
    vss::string s2("Hello");
    vss::string s3(s2);

    cout<<"s1:"<<s1<<endl;
    cout<<"s1:"<<s1<<endl;
    cout<<"3:"<<s3<<endl;
    cout<<"addr of s2:"<<&s2<<endl;
    cout<<"addr of s3:"<<&s3<<endl;
    
    return 0;
    
}
