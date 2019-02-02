# H2 - CS104
### Kyle Ashcraft - ID: 9422777848


### Compilation instructions

* To compile and run code for problem #7, run `g++ -g -Wall ulliststr.cpp ulliststr_test.cpp` followed by `./a.out` in Terminal.



Problem 6: For this problem I have two helper functions.
```void add(Node*& in, Node*& to)``` is the function that actually moves nodes from the unsorted list to either the odds or the evens, depending on which is passed as the `to` argument. The `add` function also makes use of a recursive function `void toEnd(Node*& mov)`, which recursively moves the moving pointer in `add()` to the end of the odd or even list.


Problem 7: I added a public function ```ULListStr::returnVal(size_t loc)``` as a wrapper for ```ULListStr::getValAtLoc(size_t loc)```, which was predefined as a private function, so that I could access and test the function in main() of ulliststr_test.cpp

```printList(ULListStr, size_t)``` is a function to mitigate repeated code throughout my test file. It utilizes ```ULListStr::returnVal(size_t loc)``` and handles NULL returns for with a predefined string "NULL value at index"

I completed this homework with help from CP Xiaowen Zhu