2.注意构造函数的用法，链表节点的申请

3.map的用法，count/find/erase，count计算出现次数，0或者1，find返回位置，erase删除iterator，M.erase(iter++)，注意提前保存变量，防止之后删除了而不自知

5.双指针，最长回文子串，假设pos1-pos2之间为回文串，更新时判断pos1-1与pos2+1是否相同，相同则加入，否则停止。从0-n-1遍历，初始时pos1=pos2，若pos2+1与pos1相同，加入，更新pos2=po2+1

6.记录下各个字符的二维坐标(x,y)，然后根据坐标排序即可。char与string之间的转换。还有string的方法，找子串，str.find(substr, pos)，从pos开始查找substr，返回首位下标，找不到返回string::npos，substr方法，str.substr(start,length)，str.substring(start, end)

8.太多细节了。注意str.substr(start, length)

11.sort函数自定义比较函数时的注意事项？return x<y;  if(x<y)return true ;else reutn false;第二种方式在数据量大时（999）会出错，不知道什么原因。。。

12.很傻的if else题，注意的方法有string的insert方法，str.insert(pos, substr)

15.3sum，有点麻烦，思考下vector对自定义数据的查找，set.inserst()，对自定义数据去重？vector的元素查找,find(v.begin(), v.end(), val)。最后过了311/313，剩下两个超时了。
采用双指针，复杂度降为on2

16.3sum-closest,和15一样，排序后，利用性质，利用双指针，复杂度为o(n2)。注意的是vector的拷贝初始化， vector<int> tmp(v1)      v.assign(v1.begin(), v2.begin())