# Economics
---
**Ending**  

[Main](https://github.com/khizer-kt/Economics/tree/main/work) contains all the running code for the project.  
[Scraps](https://github.com/khizer-kt/Economics/tree/main/scrap) unused code.  
Main:  
- [DriverCode](https://github.com/khizer-kt/Economics/blob/main/work/main.cpp)
- [Quicksort](https://github.com/khizer-kt/Economics/blob/main/work/sort.h)  
- [FiscalYearDetails](https://github.com/khizer-kt/Economics/blob/main/work/main.h)  
- [CustomerShopCart](https://github.com/khizer-kt/Economics/blob/main/work/main.h)  
- [ItemIdSearch](https://github.com/khizer-kt/Economics/blob/main/work/main.h)  
- [Hashing](https://github.com/khizer-kt/Economics/blob/main/work/main.h)  
- [AVL](https://github.com/khizer-kt/Economics/blob/main/work/main.h)  
- [LinkedList](https://github.com/khizer-kt/Economics/blob/main/work/main.h)
- [Data](https://github.com/khizer-kt/Economics/blob/main/work/test.csv)
- [DataForSorting](https://github.com/khizer-kt/Economics/blob/main/work/test3.csv)
- [SortedData](https://github.com/khizer-kt/Economics/blob/main/work/test4.csv)  

---   
**Time Complexities: **  
- **QuickSort O(n*log(n))** The quicksort algorithm divides the array into two halves and then recursively sorts each half. This means that the time complexity is proportional to the number of elements in the array multiplied by the number of times the array is divided (log n).  
- **SearchItem(AVL) O(log n)** Each time the function searches a node, it compares the search key (in this case, the id string) with the key of the current node. If the search key is smaller, it will search the left subtree, and if it is larger, it will search the right subtree. This process continues until the search key is found or it is determined that the key is not present in the tree.


---
Run main.cpp    
  
![image](https://user-images.githubusercontent.com/99535489/210188553-9a1bdd47-3bc5-416d-8b0d-233b5590ac03.png)    
![image](https://user-images.githubusercontent.com/99535489/210188565-65ba4953-f5bb-4fbe-94fa-05e90e2de132.png)    
![image](https://user-images.githubusercontent.com/99535489/210188579-7e91dab1-e254-4ad1-b275-122a27a81fa0.png)    
![image](https://user-images.githubusercontent.com/99535489/210188587-b948c211-26f9-4bce-b909-f9642aaba4ae.png)    
![image](https://user-images.githubusercontent.com/99535489/210188596-1bfb9106-fe7a-4dc8-8dcc-b46126cc2ed7.png)    

---
~~**Stage:4**~~  
~~5:05 AM 31st December~~  
~~Winding up the work from last two days~~  
~~- Fixed the AVL code~~  
~~- Included [hash.h](https://github.com/khizer-kt/Economics/blob/main/hash.h)~~  
~~This file is creating a hash function by getting the item_id from the CSV file then converting that id into an integer, passing it to a hash function that will give its location.~~  

---  
~~**Stage:3**~~  
~~8:26 PM 29th December~~  
~~AVL Files Added~~  
~~Parser File Upgraded to Parse data into AVL~~  

---
~~**Stage:2**~~  
~~10:14 PM 20th December~~  
~~Contributors:~~  
~~- [Khizer](https://github.com/khizer-kt)~~
~~- [Wasam](https://github.com/wasam-khan)~~
~~- [Abdul Rehman](https://github.com/ara8256)~~
  
~~Basic Functionalities that we MAY use in this project:~~  
~~- Searching for an item, using a hashtable or binary search tree~~  
~~- Sorting items by price or name (quicksort or mergesort)~~  
~~- Add or remove items in the dataset (dynamic array)~~  
~~- Calculate the total cost of a shopping cart (Heap or queue)~~  
~~- Recommendations, we can use graphs to represent relationships between items for recommending~~  
~~- Sales Commission, using hashtables we can store the sales commission codes and corresponding commission rates~~  
~~- Generating reports on sales and customer data: We can use a data structure such as a binary search tree to store and organize the sales data by various criteria (e.g., customer ID, fiscal year, category)~~  
~~- Implementing a loyalty program: We can use a data structure such as a heap to store and prioritize customer data based on their "customer since" date~~  
~~- Implementing a feature that allows users to filter and sort the items in the dataset: We can use a data structure such as a priority queue to store and prioritize the items in the dataset based on various criteria (e.g., price, quantity)~~  


---

~~**Stage:1** SCRAPPED~~   
~~1:24 AM 16th December Code commited by [Khizer](https://github.com/khizer-kt)~~  
~~- For now we are getting the data from CSV file into LinkedList and each and every data field (cell) is treated as a separate Node~~   
  
---
