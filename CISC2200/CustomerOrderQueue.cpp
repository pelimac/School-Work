/* Brandon McFarlane
CISC 2200
CustomOrderQueue.cpp
*/
#include <iostream>
#include <vector>
using namespace std;

// Create a class CustomerOrder to have the following member variables.
class CustomerOrder{
 private:
 int orderId;
 double orderAmount;
 string customerName;

 public:
  // Constructor to initialize the member variables
  CustomerOrder(int id, double amount, string name): orderId(id), orderAmount(amount), customerName(name) {}

  // Getter functions to retrieve the member variables
  int getOrderId() const { return orderId; }
  double getOrderAmount() const { return orderAmount; }
  string getCustomerName() const { return customerName; }
};

// Define a comparison function to be used for ordering CustomerOrder objects in the priority queue
bool compareOrders(const CustomerOrder* a, const CustomerOrder* b) {
  return a->getOrderId() > b->getOrderId();
}

class PriorityQ {
 private:
  int maxSize;
  vector<CustomerOrder*> queVect;  // Use vector of pointers to CustomerOrder objects

  int nItems;

 public:
  // Constructor
  PriorityQ(int s): maxSize(s), nItems(0) {
    queVect.resize(maxSize);  // Resize the vector to have the given size
  }

  // Insert a new CustomerOrder object into the priority queue
  void insert(CustomerOrder* item) {
    int j;
    if (nItems == 0) {
      queVect[nItems++] = item;
    } else {
      for (j = nItems - 1; j >= 0; j--) {
        if (compareOrders(item, queVect[j])) {
          queVect[j + 1] = queVect[j];
        } else {
          break;
        }
      }
      queVect[j + 1] = item;
      nItems++;
    }
  }

  // Remove and return the highest priority CustomerOrder object from the priority queue
  CustomerOrder* remove() {
    return queVect[--nItems];
  }

  // Return the highest priority CustomerOrder object from the priority queue without removing it
  CustomerOrder* peekMin() {
    return queVect[nItems - 1];
  }

  // Check if the priority queue is empty
  bool isEmpty() {
    return (nItems == 0);
  }

  // Check if the priority queue is full
  bool isFull() {
    return (nItems == maxSize);
  }
};

int main() {
  // Create a priority queue named orders
  PriorityQ orders(3);

  // Insert the following three CustomerOrder objects
  CustomerOrder c1(1, 100.0, "customer1");
  CustomerOrder c2(3, 50.0, "customer3");
  CustomerOrder c3(2, 300.0, "customer2");

  orders.insert(&c1);
  orders.insert(&c2);
  orders.insert(&c3);

  // Print the details of each object as you remove them from the priority queue
  while (!orders.isEmpty()) {
    CustomerOrder* order = orders.remove();
    cout << "orderId:" << order->getOrderId() << ", orderAmount:" << order->getOrderAmount()
         << ", customerName:" << order->getCustomerName() << endl;
  }

  return 0;
}