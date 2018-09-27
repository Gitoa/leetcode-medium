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

17.需要动态增长。注意的知识点？？？单个char转string， 先声明一个string str; str.push_back(char)；vector的赋值,assign，vector清空，v.clear()。

18.4sum。基本思路与3sum一致，排序后，利用性质，利用双指针，复杂度为o(n3)。居然能过。。。

19.最经典的two pointer，删除链表节点中倒数第N个节点，链表删除需要节点的前一个节点，注意的一点是当删除的为head时需要另加判断。

22.和17题类似，不断递增，同时依据题意添加判断条件，保存某次结果，下一次计算需要在上一次的结果上进行遍历增加。涉及知识点？还是char和string的关系吧。另外还有next_permutation的用法，int a[]; while(next_premutation(a,a+10));

24.链表题，简单。。。在稿纸上画好流程图就行

29.不用已有的乘法除法求模操作进行除法计算，暴力相减法在除数很小被除数很大时会超时。利用位运算来代替乘法，且相当于将商表示成二进制形式，若dividend>=divisor<<i，说明第i位为1，商加上2^i。

31.今日头条面试原题，求下一全排列，就是寻找排序大于当前排列且临当前排列最近的一项。交换的位数越低，越接近，因此从右（低位）开始查找，找到第一个i，i的低位有比i上数字更大的数，易得i右侧为递减数列，然后从右侧比i大的数中最小的那位，与i想换，此时i位右侧仍热为递减数列，进行翻转即可。

33.数列为有序数列在某位旋转后得到，查询方法时间复杂度为logn，考虑二分法。每次查找mid=(left+right)/2，若mid为所求位，返回。否则比较left和mid-1, mid+1和right。可以判断左右数列是否有序，若有序，就用有序二分法查找，无序则继续当前方式。

34.也是有序数列二分法查找，查找某个数最初和最后出现的位置，其实只要先找到任意一个等于目标的位置，因为有序，必然相等的数是连续的，利用该性质向左，向右查找即可。

36.判断是否满足数独条件，拆分成几个情况，这样比较好写。注意各个类型的初始化？？？

39.递归加回溯法，需要熟悉下。以及c++的类需要再复习下。

40.同39基本一样，就是不能重复，递归时注意条件。

43.华为面试时问的题。。。大数相乘问题，用字符串保存。分解成单个字符串与整形数相乘，两个字符串相加。注意string的各种转换。华为面试时提到了优化方法，二分法类似，感觉太麻烦了。。。

46.permutation.作弊方法直接用next_permutation()，但是要注意next_permutation前进行下排序，它只会返回在初始值之后的permutation。个人实现采用了递归，主要的话，注意容器的erase和insert方法。