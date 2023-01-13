//****************************************************************************************************
//
//      File:                Stock.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #
//
//      Course Name:         Data Structures II
//
//      Course Number:       COSC 3100 - 11
//
//      Due:                 December 1st, 2020
//
//
//      This program creates two arrays. One full of integers and the other
//		full of stock objects. Then it randomizes the order of the elements
//		in the array and presents them. Then it proceeds to do four different
//		sorting algorithems on both arrays and displaying them each time.
//		Those algorithems are QuickSort and HeapSort both in forward and
//		reverse orders.
//
//      Other files required:
//		    1.    SortedList.cpp - contains the main function
//			3.	  SortedList.h - Contains the SortedList class
//
//****************************************************************************************************

#include <iostream>
#include "SortedList.h"
#include "Stock.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

int main()
{
	//Initializing the numbers array
	SortedList<int> nums(10);

	nums.insert(43);
	nums.insert(234);
	nums.insert(54);
	nums.insert(1234);
	nums.insert(324);
	nums.insert(76);
	nums.insert(3);
	nums.insert(98);
	nums.insert(1001);
	nums.insert(176);

	//Initializing the stocks array
	SortedList<Stock> stocks(10);

	Stock s = Stock("Facebook", "FB", 293.58);
	stocks.insert(s);
	
	s = Stock("Coca-Cola", "KO", 49.66);
	stocks.insert(s);

	s = Stock("Apple", "AAPL", 118.86);
	stocks.insert(s);

	s = Stock("Nike", "NKE", 129.13);
	stocks.insert(s);

	s = Stock("Adobe", "ADBE", 495.78);
	stocks.insert(s);

	s = Stock("Microsoft", "MSFT", 223.93);
	stocks.insert(s);

	s = Stock("McDonald's", "MCD", 216.24);
	stocks.insert(s);

	s = Stock("Intel", "INTC", 45.45);
	stocks.insert(s);

	s = Stock("Amazon", "AMZN", 3309.75);
	stocks.insert(s);

	s = Stock("Google", "GOOG", 1769.03);
	stocks.insert(s);

	cout << "Inserted stocks" << endl << endl;

	//Displaying the arrays
	cout << "Inserted 10 numbers into an array and displaying them:" << endl << endl;

	nums.display();

	cout << endl << "Inserted 10 Stocks into an array and displaying them:" << endl << endl;

	stocks.display();

	//Randomizing the arrays
	cout << "Randomizing the numbers array..." << endl << endl;

	nums.randomise();

	cout << "Displaying the random numbers array: " << endl << endl;

	nums.display();

	cout << endl << "Randomizing the stocks array..." << endl << endl;

	stocks.randomise();

	cout << "Displaying the random stocks array: " << endl << endl;

	stocks.display();

	//Sorting the arrays using QuickSort both in ascending and descending orders
	cout << "Sorting the numbers in ascending order using the quicksort algorithem: " << endl << endl;

	nums.quickSortA();

	cout << "Sorted numbers array:" << endl << endl;

	nums.display();

	cout << "Sorting the stocks in ascending order using the quicksort algorithem based off of the stock's symbol: " << endl << endl;

	stocks.quickSortA();

	cout << "Sorted stocks array:" << endl << endl;

	stocks.display();

	cout << "Randomising both arrays." << endl << endl << "Numbers array: " << endl << endl;

	nums.randomise();

	nums.display();

	cout << "Stocks array:" << endl << endl;

	stocks.randomise();

	stocks.display();

	cout << "Sorting the numbers in descending order using the quicksort algorithem: " << endl << endl;

	nums.quickSortD();

	nums.display();

	cout << "Sorting the stocks in descending order using the quicksort algorithem based off of the stock's symbol: " << endl << endl;

	stocks.quickSortD();

	stocks.display();

	cout << "Randomising both arrays." << endl << endl << "Numbers array: " << endl << endl;

	nums.randomise();

	nums.display();

	cout << "Stocks array:" << endl << endl;

	stocks.randomise();

	stocks.display();

	//Sorting both arrays using the HeapSort algorithem both in ascending and descending orders
	cout << "Sorting the numbers array in ascending order using the HeapSort algorithem:" << endl << endl;

	nums.heapSortA();

	nums.display();

	cout << "Sorting the stocks array in ascending order using the HeapSort algorithem based off of the stock's symbol:" << endl << endl;

	stocks.heapSortA();

	stocks.display();

	cout << "Randomising both arrays." << endl << endl << "Numbers array: " << endl << endl;

	nums.randomise();

	nums.display();

	cout << "Stocks array:" << endl << endl;

	stocks.randomise();

	stocks.display();

	cout << "Sorting the numbers array in descending order using the HeapSort algorithem:" << endl << endl;

	nums.heapSortD();

	nums.display();

	cout << "Sorting the stocks array in descending order using the HeapSort algorithem based off of the stock's symbol:" << endl << endl;

	stocks.heapSortD();

	stocks.display();
}

//****************************************************************************************************

/*
Inserted stocks

Inserted 10 numbers into an array and displaying them:

43
234
54
1234
324
76
3
98
1001
176

Inserted 10 Stocks into an array and displaying them:

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: Apple
Symbol:AAPL
Price:118.86

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Google
Symbol:GOOG
Price:1769.03

Randomizing the numbers array...

Displaying the random numbers array:

324
54
234
1001
76
176
3
1234
98
43

Randomizing the stocks array...

Displaying the random stocks array:

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Apple
Symbol:AAPL
Price:118.86

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Facebook
Symbol:FB
Price:293.58

Sorting the numbers in ascending order using the quicksort algorithem:

Sorted numbers array:

3
43
54
76
98
176
234
324
1001
1234
Sorting the stocks in ascending order using the quicksort algorithem based off of the stock's symbol:

Sorted stocks array:

Company Name: Apple
Symbol:AAPL
Price:118.86

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Nike
Symbol:NKE
Price:129.13

Randomising both arrays.

Numbers array:

98
54
43
1001
176
1234
234
76
324
3
Stocks array:

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Apple
Symbol:AAPL
Price:118.86

Sorting the numbers in descending order using the quicksort algorithem:

1234
1001
324
234
176
98
76
54
43
3
Sorting the stocks in descending order using the quicksort algorithem based off of the stock's symbol:

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Apple
Symbol:AAPL
Price:118.86

Randomising both arrays.

Numbers array:

176
324
1001
43
98
3
76
234
54
1234
Stocks array:

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Apple
Symbol:AAPL
Price:118.86

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Nike
Symbol:NKE
Price:129.13

Sorting the numbers array in ascending order using the HeapSort algorithem:

3
43
54
76
98
176
234
324
1001
1234
Sorting the stocks array in ascending order using the HeapSort algorithem based off of the stock's symbol:

Company Name: Apple
Symbol:AAPL
Price:118.86

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Nike
Symbol:NKE
Price:129.13

Randomising both arrays.

Numbers array:

98
54
43
1001
176
1234
234
76
324
3
Stocks array:

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Apple
Symbol:AAPL
Price:118.86

Sorting the numbers array in descending order using the HeapSort algorithem:

1234
1001
324
234
176
98
76
54
43
3
Sorting the stocks array in descending order using the HeapSort algorithem based off of the stock's symbol:

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: McDonald's
Symbol:MCD
Price:216.24

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: Apple
Symbol:AAPL
Price:118.86
*/