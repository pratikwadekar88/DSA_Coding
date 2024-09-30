/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/


class MedianFinder {
public:
    // Two heaps (priority queues):
    // maxpq is a max-heap for the left half of the numbers
    // minpq is a min-heap for the right half of the numbers
    priority_queue<int> maxpq; // Max heap (by default in C++)
    priority_queue<int, vector<int>, greater<int>> minpq; // Min heap

    // Constructor to initialize the object
    MedianFinder() { }

    // Function to add a number to the data structure
    void addNum(int num) {
        // If max heap is empty or the number is smaller than the max element in maxpq,
        // we add it to maxpq (the left half).
        if(maxpq.empty() || maxpq.top() > num){
            maxpq.push(num); // Add to maxpq
        }else {
            // Otherwise, add the number to minpq (the right half)
            minpq.push(num); 
        }

        // Balancing the heaps:
        // If maxpq has more than one extra element compared to minpq, we need to move
        // the largest element from maxpq to minpq.
        if(maxpq.size() > minpq.size() + 1){
            minpq.push(maxpq.top());  // Move top of maxpq to minpq
            maxpq.pop();  // Remove the top from maxpq
        }

        // Similarly, if minpq has more elements than maxpq, move the smallest element
        // from minpq to maxpq.
        if(maxpq.size() + 1 < minpq.size()){
            maxpq.push(minpq.top());  // Move top of minpq to maxpq
            minpq.pop();  // Remove the top from minpq
        }
    }
    
    // Function to find the median of the current data stream
    double findMedian() {
        // If both heaps have equal size, the median is the average of the top elements
        // from both heaps.
        if(maxpq.size() == minpq.size()){
            return (maxpq.top() + minpq.top()) / 2.0;
        } 
        // If maxpq has one extra element, the median is the top of maxpq.
        else if(maxpq.size() == minpq.size() + 1){
            return maxpq.top();
        } 
        // Otherwise, the median is the top of minpq (if minpq has one extra element).
        else {
            return minpq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
