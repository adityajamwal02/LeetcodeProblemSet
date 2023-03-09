/*
Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.
A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
1 <= xi.length <= 4
xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
Leading zeros are allowed in xi.
For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

Example 1:
Input: queryIP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:
Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:
Input: queryIP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

/// Regex Solution

class Solution {
public:
    string validIPAddress(string queryIP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        if(regex_match(queryIP, ipv4)){
            return "IPv4";
        }else if(regex_match(queryIP, ipv6)){
            return "IPv6";
        }else{
            return "Neither";
        }
    }
};

/// Another Solution

class Solution {
public:
    string validIPAddress(string str)
    {
        if(check_ipv4(str)==true)
       {
           return "IPv4";
       }
       else if(check_ipv6(str)==true)
       {
          return "IPv6";
       }
       return "Neither";
    }
    bool check_ipv4(string s)
    {
        int idx=0;
       // bool flag=true;     //considering the ip address to be valid initially

        int count=0;

        string temp="";

        while(true)
        {
            if(s[idx]=='.')
            {
                if(temp.length()>3) return false;

                if(temp.length()==0)
                return false;

                int num=stoi(temp);
                //checking for the leading zeros
                if(num>0 and temp.length()>0 and temp[0]=='0')
                return false;
                else if(num==0 and temp.length()>1 and temp[0]=='0')
                return false;


                if(num>=0 and num<=255)
                {
                    count++;
                    temp="";
                }
                else
                {
                    return false;
                }
                //code
            }
            else if(idx>=s.length())
            {
                if(temp.length()>3) return false;

                if(temp.length()==0)
                return false;
                //code
                int num=stoi(temp);


                if(num>0 and temp.length()>0 and temp[0]=='0')
                return false;
                else if(num==0 and temp.length()>1 and temp[0]=='0')
                return false;

                if(num>=0 and num<=255)
                {
                    count++;
                    temp="";
                }
                else
                {
                    return false;
                }
                break;
            }
            else if(s[idx]>='0' and s[idx]<='9')
            {
               temp=temp+s[idx];
            }
            else
		    {
                return false;
            }
            idx++;
        }
        if(count==4) return true;
        return false;
   }
    bool check_ipv6(string str)
   {
        int idx=0;
        int count=0;    //count-->8
        string temp="";
        while(true)
        {
            if(str[idx]==':')
            {
                //just need to check the empty string
                if(temp.length()==0)
                return false;
                if(temp.length()>4)
                return false;

                count++;
                temp="";
                idx++;
            }
            else if(idx>=str.length())
            {
                //code
                if(temp.length()==0)
                return false;
                if(temp.length()>4)
                return false;

                count++;
                temp="";
                idx++;

                break;
            }
            else if((str[idx]>='0' and str[idx]<='9') or (str[idx]>='a' and str[idx]<='f') or (str[idx]>='A' and str[idx]<='F'))
            {
                temp=temp+str[idx];
                idx++;
            }
            else
            {
                return false;
            }
        }
        if(count==8)
        return true;

        return false;
   }
};
