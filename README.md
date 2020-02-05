
 # STL_demo
 STL标准库下的demo
 ## C++基础

 ### Str
			自写字符相关操作
 
 ## 容器demo/container_demo
  -------------------------------------------------------------
 ### mVector.cpp	

 
			 向量容器
			 
			 不支持头删和头插，是一段连续的内存，头部插入删除，后面内存需要移动，效率低
 

 
 ### mString.cpp	
 
 ### mList.cpp		
 
			链表
			
 ### mArray.cpp		

			固定大小，不支持插入。

 ### mDeque.cpp		
 
			双端数组

 ### mQueue.cpp		

			队列
 
			队列先进先出，只能操作队头和队尾，队头出，不能随机访问，不能遍历

 ### mStack.cpp  	

			栈
 
			先进后厨，只能操作栈顶，不能随机范围，不支持遍历

 ### mSet.cpp		

			 关联式容器，底层结构是用二叉树实现,
			 
			 set:自动排序，不插入重复数据 
			 
			 multiset允许容器中有重复的元素

 ### mMap.cpp 
 
			关联式容器，底层结构是用二叉树实现,里面的元素都是对组 pair存放
 
			map:自动排序，不插入重复数据 
 
			multimap允许容器中有重复的元素
			
 ### mPair.cpp

			对组 :first和second访问  键值和值的绑定
			
-------------------------------------------------------------
 ## 仿函数demo
 
 ### mFunctor.cpp
 
			仿函数的基本使用


 ### mPredicate.cpp

			谓词:
			返回bool类型的仿函数称为谓词
						
			如果operator()接受一个参数，那么叫做一元谓词
						
			如果operator()接受两个参数，那么叫做二元谓词

### mBuiltInFunction.cpp

			STL 内建了一些函数对象

			分类:
			算术仿函数
			关系仿函数
			逻辑仿函数

			使用内建函数对象，需要引入头文件#include <functional>

			算术仿函数:
			template<class T> T plus<T>			//加法仿函数
			template<class T> T minus<T>		//减法仿函数
			template<class T> T multiplies<T>	//乘法仿函数
			template<class T> T divides<T>		//除法仿函数
			template<class T> T modulus<T>		//取模仿函数
			template<class T> T negate<T>		//取反仿函数

			关系仿函数:
			template<class T> bool equal_to<T>			//等于
			template<class T> bool not_equal_to<T>		//不等于
			template<class T> bool greater<T>			//大于
			template<class T> bool greater_equal<T>		//大于等于
			template<class T> bool less<T>				//小于
			template<class T> bool less_equal<T>		//小于等于

			逻辑仿函数
			template<class T> bool logical_and<T> //逻辑与
			template<class T> bool logical_or<T> //逻辑或
			template<class T> bool logical_not<T> //逻辑非
## 算法/mAlgorithm

### mAlgorithm.cpp

基础算法的使用
			遍历
			for_each(iterator beg, iterator end,_func)

			-------------------------------------------------------------
			搬运容器到另一个容器中
			transform(iterator beg1, iterator end1, iterator beg2, _func);

			beg1 源容器开始迭代器
			end1 源容器结束迭代器
			beg2 目标容器开始迭代器
			_func 函数或者函数对象
			-------------------------------------------------------------
			查找
			find(iterator beg, iterator end, value);

			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			value 查找的元素
			-------------------------------------------------------------
			find_if(iterator beg, iterator end, _Pred);

			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			_Pred 函数或者谓词（返回bool类型的仿函数）
			-------------------------------------------------------------
			adjacent_find(iterator beg, iterator end);

			查找相邻重复元素,返回相邻元素的第一个位置的迭代器
			beg 开始迭代器
			end 结束迭代器
			-------------------------------------------------------------
			bool binary_search(iterator beg, iterator end, value);

			查找指定的元素，查到 返回true 否则false
			注意: 在无序序列中不可用
			beg 开始迭代器
			end 结束迭代器
			value 查找的元素
			-------------------------------------------------------------
			count(iterator beg, iterator end, value);
			统计元素出现次数

			count_if(iterator beg, iterator end, _Pred);
			按条件统计元素出现次数
			
			beg 开始迭代器
			end 结束迭代器
			value 统计的元素
			-------------------------------------------------------------

### mAlgorithm2.cpp

			-------------------------------------------------------------
			常用排序算法
			sort			-- 对容器内元素进行排序
			random_shuffle  -- 洗牌 指定范围内的元素随机调整次序
			merge			-- 容器元素合并，并存储到另一容器中
			reverse			-- 反转指定范围的元素
			-------------------------------------------------------------
			sort(iterator beg, iterator end, _Pred);
			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			_Pred 谓词
			-------------------------------------------------------------
			random_shuffle(iterator beg, iterator end);
			指定范围内的元素随机调整次序
			beg 开始迭代器
			end 结束迭代器
			-------------------------------------------------------------
			merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			容器元素合并，并存储到另一容器中

			!!!注意: 两个容器必须是有序的,都是升序或者降序

			beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
			dest 目标容器开始迭代器
			-------------------------------------------------------------



 ### mAlgorithm3.cpp
 
 			-------------------------------------------------------------
			copy		-- 容器内指定范围的元素拷贝到另一容器中
			replace		-- 将容器内指定范围的旧元素修改为新元素
			replace_if	-- 容器内指定范围满足条件的元素替换为新元素
			swap		-- 互换两个容器的元素(大小可以不一致)swap交换容器时，注意交换的容器要同种类型
			-------------------------------------------------------------
			目标容器需要提前开辟空间
			copy(iterator beg, iterator end, iterator dest);
			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			dest 目标起始迭代器

			-------------------------------------------------------------
			replace(iterator beg, iterator end, oldvalue, newvalue);
			将区间内旧元素 替换成 新元素
			beg 开始迭代器
			end 结束迭代器
			oldvalue 旧元素
			newvalue 新元素

			-------------------------------------------------------------
			replace_if(iterator beg, iterator end, _pred, newvalue);
			按条件替换元素，满足条件的替换成指定元素
			beg 开始迭代器
			end 结束迭代器
			_pred 谓词
			newvalue 替换的新元素
			-------------------------------------------------------------
			
### mNumeric.cpp

			#include <numeric>

			-------------------------------------------------------------
			accumulate		-- 计算容器元素累计总和
			fill			-- 向容器中添加元素
			-------------------------------------------------------------
			accumulate(iterator beg, iterator end, value);
			计算容器元素累计总和
			beg 开始迭代器
			end 结束迭代器
			value 起始值
			-------------------------------------------------------------
			fill(iterator beg, iterator end, value);
			向容器中填充元素
			beg 开始迭代器
			end 结束迭代器
			value 填充的值
			-------------------------------------------------------------
			
### mAlgorithm4.cpp

			常用集合算法
			#include <algorithm>
			-------------------------------------------------------------
			set_intersection // 求两个容器的交集
			set_union // 求两个容器的并集
			set_difference // 求两个容器的差集
			-------------------------------------------------------------
			set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			求两个集合的交集
			注意:两个集合必须是有序序列
			beg1 容器1开始迭代器 
			end1 容器1结束迭代器 
			beg2 容器2开始迭代器 
			end2 容器2结束迭代器 
			dest 目标容器开始迭代器
			-------------------------------------------------------------
			set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			求两个集合的并集
			注意:两个集合必须是有序序列
			beg1 容器1开始迭代器 
			end1 容器1结束迭代器 
			beg2 容器2开始迭代器 
			end2 容器2结束迭代器 
			dest 目标容器开始迭代器
			-------------------------------------------------------------
			set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			求两个集合的差集(前 - 后)
			注意:两个集合必须是有序序列
			beg1 容器1开始迭代器 
			end1 容器1结束迭代器 
			beg2 容器2开始迭代器 
			end2 容器2结束迭代器 
			dest 目标容器开始迭代器
			-------------------------------------------------------------

 ## Debug
 
			TRACE()
 ## Str

			字符拷贝操作


 
 
 
 
 
 