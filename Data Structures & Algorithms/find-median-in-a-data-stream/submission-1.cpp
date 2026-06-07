class MedianFinder {
public:
    priority_queue<int>left_max_heap;
    priority_queue<int, vector<int>, greater<int>>right_min_heap;

    MedianFinder() {}
    
    void addNum(int num) 
    {
        if(left_max_heap.empty() || num < left_max_heap.top())
            left_max_heap.push(num);
        else
            right_min_heap.push(num);
        
        //adjusting 
        //We need to keep the size of left max heap pq one extra when n is odd otherwise same 
        if(left_max_heap.size() < right_min_heap.size())
        {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        else if(left_max_heap.size() - right_min_heap.size() > 1)
        {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
    }
    
    double findMedian() 
    {
        if(left_max_heap.size() == right_min_heap.size())
            return (double)(left_max_heap.top() + (double)right_min_heap.top())/2.0;

        return (double)left_max_heap.top();
    }
};

//https://www.youtube.com/watch?v=jnj87BSi9Is ---- the OG explanation
