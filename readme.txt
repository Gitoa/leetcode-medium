﻿2.注意构造函数的用法，链表节点的申请

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

<<<<<<< HEAD
46.permutation.作弊方法直接用next_permutation()，但是要注意next_permutation前进行下排序，它只会返回在初始值之后的permutation。个人实现采用了递归，主要的话，注意容器的erase和insert方法。

47.作弊方法直接用set。正常解法就是利用相同的数不进行交换的思路。
=======
46.permutation.作弊方法直接用next_permutation()，但是要注意next_permutation前进行下排序，它只会返回在初始值之后的permutation。个人实现采用了递归，主要的话，注意容器的erase和insert方法。v.insert(v.begin()+i, num)。递归其实是DFS的，DFS用标记记录是否加入，我直接在传入时去掉了已加入的数字。此外还有采用swap的方法。

47.permutation.此时有重复数字，用DFS方法做，注意两点。1.保证已经入列的数不再入列（指同一个数，不是相等数），可以用visited数组标记。2.保证在相等的数不会重复出现在同一个位置，可以通过排序，根据num[i]==num[i+1]来判断相等，同时前面的数总是先插入的，若visited[i]==0,说明i已经在该位判断过，不需要再将i+1进行操作。

48.数组旋转，按照题目要求空间复杂度是0？作弊的话直接申请个vector<vector<int>>就可以了。符合标准的解法，观察后发现就是把第i行换成第n-i列，从尾行开始操作，尾行的元素应该作为第一列，在头部插入，倒数第二行应该在第二列插入，依次类推，插入时要判断当前行元素是原来的元素还是插入的。知识点的话？v.insert(v.begin(), nums)
>>>>>>> 81cacd30f3a4605b5e3bc05bec64c340cc8b81b9

49.蛮简单的，暴力方法能过99%的case。使用map后过了，其实主要思想还是一致的，就是在查找时map更快了。（学习一下map是怎么实现的？）

50.蛮简单的，暴力是不可能的，用位运算，把n看成二进制形式，则非0位的值需要相乘，而非0位的底数可以根据上一位的底数得到。注意的就是int型的最小值在转换为正值时会超出表达范围，因此用long long保存。

54.其实很简单的题。。。针对四个顶点进行循环，循环后进行更新，就是要注意几个细节，一是当只有一行或只有一列时会重复，还有当输入为空时注意访问会不会越界。还有insert的用法，v.insert(v.end(), tmp.begin(), tmp.end())。在v的最后插入tmp。

55.原理很简单，用DFS的方法做，可以最快的返回结果。注意的话递归的退出，用一个外部bool来判断是否继续。超时了是为什么。。。有一个例子没过。（忘了加visited数组了导致重复计算）

56.也是很简单的题目。注意分析特性就好，先进行排序，然后进行插入更新，若start小于等于end，则重合，进行更新，否则直接插入。

59.简单。。。也是旋转矩阵，同样利用四个顶点的更新来做。注意vector生成多维数组的方式。vector<vector<int>> ans; vector<int>tmp(n); ans.push_back(tmp); 或者申请后进行resize。vector<vector<int>> ans(n); while(i<n){ans[i++].resize()};

60.又是permutation，DFS递归做，最傻的方式就是从头开始遍历并计算次数，建立一个全局变量记录是否还需要继续递归。

61.链表，蛮简单的题目。就是要注意判断初始链表是否为空。一般都会用两个指针来解题。

62.求排列组合。第一反应是用DFS遍历所有结果，超时。发现规律可以用DP来做。自己多用例子进行推算比较容易发现规律。注意下初始化？memset(first, val, length)或者fill(first, last, val);

63.同第62基本一样，就是需要判断某个位置是否能“通过”，若不能通过则置0，状态转移方程依然为DFS[i][j]=DFS[i-1][j]+DFS[i][j-1]

64.与之前的题一样，也是动态规划的题，状态转移方程为dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j]，但是要注意边界条件的初始化。此外还有vector的初始化，vector<int> tmp(len, val)

71.弱智题。。。就是不断的分类讨论即可。但是要注意string的操作，比如find, rfind, substr, erase。

73.第一想法是在原矩阵上进行标记，用不用的数字标记（如-1），但是结果输入范围是int。第二种方法就是将o(m+n)的方法进行改造，将原本需要的额外空间，放到第一列和第一行中。

74.有序矩阵中查找，用二分法，将在数组上的过程转化到矩阵中即可。注意边界条件，矩阵为空。

75.三种颜色排序。只要知道不断更新第一项队列和第三项队列即可。

77.求排列组合，用DFS的方法做，注意边界条件和递归条件。

78.subset，DFS做，注意条件即可。。。

79.DFS。vector的初始化出错了。。。真的是。vector<int>tmp (len, val)。

80.好蠢的题目。

81.将有序数组按某位旋转后得到的数组中查找，之前有类似题，这次出现了重复，在用二分法判断时需要注意。当出现等于时应该判断为非有序。

82.删除有序链表中出现的重复数。用三个结点，第一个为以处理过的链表的最后一个结点，第二个第三个为下一个和下下个，当重复时，不断遍历第三个的next，直到为NULL或不等，此时sec和third之间部分为相等，删除。注意更新各个结点的细节。

86.让链表小于val的数均位于大于等于val的数的左侧，且保持原始排序。开辟两个新链表，一个保存小于val的，另一个保存大于等于val的，然后二者合成就行。

89.插入0-pow(2, n)的数字，保证相邻数不同位的数量为一。0-pow(2, n-1)顺序排列，此时必满足条件，然后将其反序赋值给另外一个数组，该数组也满足条件，全部加上pow(2, n-1)，即为剩余答案剩余数组，且与之前的数组仅首位不同，满足条件，插入就可得到答案。注意vector的insert。

90.开始做时subset的生成判断条件都错了。。。该题中有重复数，因此先排序，然后在判断是否加入某个数时，若与前一个数相同，仅当前一个数加入的清况下继续。

91.啥题目。。。边界条件都不说清楚。01可以，101中的01又不可以，不搞了不搞了。（251 / 258 test cases passed.）不写了。

92.局部链表旋转，记录下初始位前一位，记录下最后一位后一位，中间部分用三个临时变量完成旋转，再拼接在一起就好了。

93.注意下细节。。。substr(pos, len).

94.二叉树的中序遍历。递归法最简单，考虑用迭代法做，此外还有Morris法，用到了线索二叉树的思想：
	1.若左子树为空，输出当前结点，更新当前结点为其右子树。
	2.若左子树不为空，找到当前结点的前趋：
		1）若前趋的右子树为空，令前趋右子树为当前结点，当前结点更新为当前结点左子树
		2）若前趋右子树为当前结点，更新右子树为空，输出当前结点更新当前结点为当前结点右子树
	3.重复1、2直到当前结点为空
	
	递归迭代的要注意stack的运用，s.top(), s.empty(), s.pop(), s.push。
	
95.二叉查找数，根结点左侧均不大于根结点，右侧均不小于根结点，考虑递归，createNode(left, right)。但是给定一个序列，可以返回多个结果，因此需要用vector来保存，且要注意申请新的TreeNode地址，否则会覆盖。
96.二叉查找树，这次只需要计算数量。很容易就能找到递归方法，但是会超时，展开用迭代完成。注意vector的初始化。

98.判断二叉查找树，二叉查找数其实就是二分法查找有序数列的数据结构，因此中序遍历为有序数列的就是二叉查找树，减少空间复杂度，只用两个整形数进行相邻比较即可。

102.二叉树的层次遍历，很简单的。。。但是用了set之后出现了莫名其妙的问题？猜测是因为set会自行排序，因此直接用vector模拟set。

103.层次遍历，z型，和102一样，就是需要进行一次翻转判断。

105.从中序遍历和先序遍历构造二叉树，蛮简单的，递归完成。

106.从中序遍历和后序遍历构造二叉树，和105基本一样，递归完成。

109.虽然是要转换为平衡二叉树，但是本题可以不考虑旋转过程，直接分为作为两边即可，算是hack的方法吧？和之前的构造二叉树过程类似。

113.二叉树的深度优先遍历,DFS,注意点在于可能会有负数。DFS一开始没写对，还是需要熟练写阿。

114.将二叉树按照先序遍历的顺序构造成只有右子树的形态，采用内联的方法。如果存在左子树，找到左子树的最右结点，将右子树作为最右结点的右子树，将左子树设置为右子树，遍历右结点，依次类推。

116.满二叉树，结点添加了next指针，令next指针指向其同一层的下一个结点，最好想的就是用层次遍历，但是要求空间复杂度为O(1)，因此考虑用递归方法。既然有next指针，就利用next指针进行遍历。

117.同116,但是这次不是完全二叉树，因此比较麻烦，添加数据结构fcNode同时记录父亲结点与孩子结点，根据父亲结点与孩子结点的关系获得孩子结点的next，可能是右孩子，也可能是父亲结点next链上的某个结点的孩子结点，利用fcNode进行遍历。

120.三角形状数组，寻找最短路径，最傻的办法就是利用和原数组一致的空间，保存每个位置的最短值，利用该值更新下一层的值。O(n)的方法怎么搞？用DFS是能实现空间O(n)，但是会超时。

127.每次只能变换一个字母，并且只能从字典中找中间值，变化到目标string，想法就是从目标string开始逆向，将每次满足条件的string保存起来，进行判断，再在这些string的基础上继续查找。需要注意的是vector的erase操作。

129.遍历所有从根结点到叶子结点的路径，再对路径进行操作，蛮简单的。。。

130.其实就是dfs的题，很简单，但是题目说明错了。

131.将字符串分解为回文数子串集合，其实也是dfs的题，但是步骤比较多。首先需要获得所有回文子串，将回文子串按照开始位置进行归类，然后根据回文子串的位置进行遍历，当前开始位置为pos，结束位置为nextPos，则下一个回文子串的开始位置自然为nextPos+1，如果该位置无子串，返回，如果该位置为长度len，路径完成，所以是dfs题。

134.额这算什么题？？？只要一直遍历就可以得出答案的题，但是有剪枝过程，若某次查找到i才发现汽油不够，那么下一次只需从i+1开始查找，因为i之前的肯定不满足，同时可以判断最后剩下多少汽油可以从0开始。

138.很简单，其实就是一个单链表，但是每个结点多了一个random指针，指向任意地址，因此仅仅根据链表得next关系不好赋值，将地址用数组保存，利用数组的位置关系进行操作。

139.其实也是DFS题型，但是需要自己设计路径，map代表了路径，下表代表了起始位置，map[i]代表了能达到的位置集合，利用DFS判断是否能到达路径，但是在设计时需要减少重复的路径，同时需要进行剪枝。注意的是vector的排序，sort(v.begin(), v.end(), cmp)，cmp返回true说明不变。

142.给出链表的循环开始位置

143.按照一定规律重排链表，由于需要用到位置信息，所以用数组保存后再进行操作会比较方便。

144.利用迭代的方法前序遍历二叉树，递归的方法存在循环，效率低，容易栈溢出等问题。前序遍历利用栈。

147.对链表进行插入排序。链表题，一般想到用多个指针来记录信息。

148.O(nlogn)的排序方法，快排，归并，堆排序，排除快排和堆排序，使用归并，递归实现，复习归并并且用链表实现。

150.对波兰表达式进行计算，波兰表达式无需括号，只需要引入一个栈就可以实现了。

151.对句子进行反转，以单词为最小单位，并且空间复杂度为O(1)。首先对整个句子进行反转，然后根据空格对各个单词进行再反转，还要删除首尾空格以及多余的内部空格。

152.最大连续子串乘积，只需要记录最大的正值和最小的负值即可，然后根据当前位置数字的正负零进行分类判断。

153.原有序数列，在某个位置进行了反转拼接，找出数列中的最小值，考虑二分法，根据mid值划分区间，直到剩下两个数，再根据这两个数的情况讨论特殊情况。

162.找到peak元素，就是该元素左右元素均小于该元素，O(n)遍历很简单。。。logn的方法不清楚（使用二分法是肯定的，根据nums[mid]和nums[mid+1]进行更新）

165.逻辑很简单的题，但是边界条件容易忽略，根据'.'分区间，再逐区间比较，然后考虑下边界条件。

179.将数组排列成最大的数返回，考虑大数问题，用string保存，同时利用to_string方法实现int到string转换，然后string的比较是按位进行的，根据acsii码，长度不同时较长的大。

187.字符串遍历比较，暴力的方法时间复杂度太高了：遍历，每次取长度为10的字符串，在余下的空间中查找是否存在重复的，重复则加入set，string.find(str, len)，set.count()，set.insert()。AC代码去掉了在余下字符串中find的操作，利用两个set实现查重，但是时间复杂度还是偏高。使用位操作速度会快很多，Bit Manipulation。

199.二叉树从右侧看，其实就是每一层最右的结点，用层次遍历很容易就完成，但是速度有点慢。同时注意到队列queue的用法，q.push(), q.pop(), q.front(), q.back(), q.empty()

200.其实就是图的遍历，BFS,DFS，将连通的图找出来，注意在使用队列以及vis标记是否访问时，在加入队列时就应该把vis设置成true，否则会重复入列。用到了pair的用法，pair<type, type> p(val1, val2)，p.first， p.second。

201.Bit manipulation。[n, m]，将范围内的各个数进行按位与，返回结果，暴力遍历自然会超时，研究后有规律：若n的位数小于m，那结果必然为0，位数相同时，从高位到低位找到第一个不同的位，此时必有高位为1,低位为0,且这之后的位在与过程中必然会出现0，因此与结果为0,所以只要对最高位至该位进行计算即可，但是速度好像很慢？？？思路是对的，但是要改成位操作。

207.有向图中环的判断，需要复习一下图的知识了，用dfs做，用-1、0、1标记未访问，正在访问，已访问状态，若dfs过程中遇到正在访问的，说明存在环。注意vector的初始化，vector<int> v(length)，length表示长度，并不会初始化成长度为一内容为length的vector。（本题其实为经典的拓扑排序，需要好好复习了）

209.蛮简单的题，找到最短连续子序列，和大于给定值。从左往右遍历，若[left,right)小于给定值，则令right右移，直至大于等于给定值，若大于等于给定值，则left左移，直至小于，期间一直更新最小值，循环上述两个过程。

210.图，拓扑排序的题，用邻接表的方法记录图，用队列记录当前可访问结点，同时记录各点入度，以及是否入列，根据当前结点更新其邻接结点的入度（-1），若入度为0且未入列过就入列，直至所有结点都判断过。若入列过的结点数小于总结点数，说明存在环。

213.首尾不能同时出现，不能有相邻，找出队列最大值，看了提示，可以分解为从[0, n-1]和[1, n]的问题，不用考虑首尾因素，更简单了，利用Max数组，Max[i]表示i位前最大值，因此以i+1为结尾的最大值为nums[i+1] + Max[i-1],但是在更新Max[i+1]时要考虑此时Max[i]可能比nums[i+1]+Max[i-1]大。

215.返回未排序数组中第K大的数，很明显的排序题，暴力方法，直接用sort排好序，选择第K个数。正确解法，用快排的partition进行分治，若p不等于K，则根据p<k?在[left, p) (p, right]中继续partition，这种方法比sort还慢？只能说STL的sort真的很快。。。还有用堆排序的。复习下排序算法（插入、选择、交换、归并）

216.[1, 9]中找出k个数，和为n，不能重复，其实就是对个数为k的排列组合进行求和并且判断？在构造排列组合的过程中进行一些剪枝操作。类似dfs。

220.判断是否存在间隔小于等于k且差小于等于t的项，考虑分割到k个相邻项中先排序，再比较查找，但是每次都要对k项排序，其实部分已经有序了，考虑从有序k项中删除num[i]，并添加num[i+k]时，时间复杂度较大，如果用红黑树，插入查找就很快了，所以用set或者map（内部用红黑树实现）。

221.计算矩阵中最大的正方形，根据特性递归实现，给定fir[top, left], sec[bottom, right]，假设fir,sec组成的正方形满足条件，即内部都是1，若[bottom+1, right+1]在数据范围内且为1，且bottom+1那一行和right+1那一列全为1（加入的全为1），则可更新sec。

222.计算完全二叉树的结点数目，暴力法超时，完全二叉树有个特性，其左右子树可能全为满二叉树，或者一个满二叉树一个完全二叉树，对满二叉树可以用公式计算，判断满二叉树只要判断其左右高度是否一致，因此可以递归求解。

223.给定两个矩阵的左下角点与右上角点，计算其覆盖面积，其实就是求二者重叠的面积，需要不断的分类讨论，用一个函数计算A<E的情况，当A>E时互换两个矩阵的位置就行了。

227.给定计算表达式，返回计算结果，先将表达式转换为后缀表达式，再根据后缀表达式进行计算。但是运算符号的优先级有点问题。。。优先级一致时也应该弹出？？？

228.送分题？？？给定有序数组，从左到右返回连续区间。用两个指针从左到右记录连续区间，当nums[right] = nums[right-1]+1时，更新。不等于时，区间结束，更新left=right, right=left+1，继续。

229.感觉作弊了这方法，先排序，再判断第i位与第i+len/3是否相同，根据结果更新。但是这样的时间复杂度应该是nlog(n)才对（排序），不符合要求。正确方法是用摩尔投票法 Moore Voting。

230.在二叉查找树中查找第K小的结点，根据二叉查找树的性质，利用先序遍历即可，第k个被访问的结点即第k小的数。

236.在二叉树中查找两个结点的最近公共父节点，简单思路就是把二者的路径求出来，找到共同路径的最后一项，但是保存路径空间较大。递归做法，判断其左右子树是否包含，若二者都在同一个子树，则最近结点不是当前结点，只有当二者分布在左右两个子树或者当前结点恰为其中之一时才返回。

238.给定数组，返回除了某位的所有项的乘积，最容易想到的是先求得所有项的乘积，除以特定位的数字，但是题目要求不能用除法，看了他人解法其实思路也很简单，就是该位的左方乘积乘以该位的右方乘积。

240.给定二维数组，数组上每列递增，每行也是递增，在该数组中判断是否存在target数，根据数组规律不断缩小查找范围，不断更新右上角的数字，右上角右侧的数均大于它，其上部的数均小于它。

241.给定表达式，自行添加括号，返回所有可能的计算结果，其实就是返回所有后缀表达式，用栈保存操作符，根据操作符的添加顺序来产生不同的括号效果，具体看代码。

264.ugly number,其约数为2，3，5，求第n位的ugly number。设当前ugly number位U1，则下一个ugly number为之前的ugly number中乘以2、3、5的一个，且大于U1，因此找到ugly number中乘以2、3、5后恰大于U1的数，并且取最小值即可。

274.求论文的h因子，看不懂。

279.将一个数分解为最少的平方的和，利用了动态规划，f(n+1)可由前n项计算而得，f(0)=0, f(1)=1，n+1必由前n项加上一个数得到，仅考虑该数是平方的情况，有f(n+1)=min(f(n+1), f(n+1-i*i) + 1)，f(n+1-i*i)位上的数加上一个平方i*i即为n+1，此时个数加一，i的范围为[1, i*i<=n+1]。

289.生命游戏，就是根据活邻居的数量来进行更新，用一个同样大小的矩阵保存邻居数量，遍历当前矩阵，若为1,则更新其邻居的活邻居数量，最后根据该矩阵依次判断。

309.给定每天的股票价格，返回通过买卖股票能赚取最大的利益，不能累计购买，卖出后有一天冷却。用动态规划的思想来做，用buy[i]保存第i天前最后一次操作是买入最大的利益，sell[i]表示第i天前最后一次操作时卖出的最大利益，则有状态转移方程:buy[i] = max(buy[i-1], sell[i-2]-price), sell[i] = max(sell[i-1], buy[i-1]+price)。

310.给定无向图，求其所能组成的高度最小的树，返回根结点，暴力的办法就是用DFS对每个结点进行遍历求深度，超时。高度最小的树的根结点是位于图“中间”的，非叶子结点，每次遍历将叶子结点去掉（入度为一），直至剩下一个或者两个结点，即为答案。

318.给定字符串数组，返回没有相同字符的字符串的长度乘积的最大值，暴力方法就是逐个判断，正确解法是用位操作，用int整数每一位来保存某个字母是否出现。位操作需要复习。

322.硬币兑换，给定一定面值的硬币，给定一个值，让硬币和等于该值，求需要的最少的硬币的数量。本人思路就是不断更新能获得的值，在值的基础上加上基础硬币就是新的能得到的值，不断更新，直到等于目标值。有点像背包问题？？？

328.把链表按照索引的奇偶分成两队。。。