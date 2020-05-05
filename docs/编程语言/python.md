# Python 语言基础知识

记录用 python 刷 leetcode 必须了解的特性，主要是数据结构的表示。

## 基础知识

### import

记录各种需要包含的库

```python
# 后置返回类型 List
from typing import List
```

### 除法运算

```python
c = int(a / b) # 实现与C语言一致的整数除法
```

## 数据结构

### 堆

引入包： `from queue import PriorityQueue`

定义：`minHeap = PriorityQueue()  # 默认建立小顶堆`

判空: `minHeap.empty()`

添加元素：`minHeap.put((key,value))`
不能传入自定义的比较函数，但是可以传入元组，根据key的值建立小顶堆

堆顶元素：`minHeap.get()` 取得并删除，与C++中的top()不同

**注意**：传入元组的时候如果key相同, 会进一步比较value, 如果value是自定义类型而且没有定义比较函数，会报错，这里要特别注意。

大部分使用情况，可以通过传入元组`(key, data)`控制堆的排序方式， 如果不能满足要求，可以在自己定义的类型上定义比较函数。