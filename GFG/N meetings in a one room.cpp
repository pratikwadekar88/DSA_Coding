//Greedy approach

struct data {
    int start; // Start time of the meeting
    int end;   // End time of the meeting
    int pos;   // Position/index of the meeting in the original array
};

class Solution {
  public:
    // Static comparator function to sort meetings based on their end times.
    // This helps in scheduling meetings that finish earlier, allowing more
    // meetings to fit into the schedule.
    bool static comp(struct data val1, struct data val2) {
        return val1.end < val2.end;  // Returns true if the first meeting ends before the second
    }

    // Function to find the maximum number of meetings that can be scheduled
    // without overlap in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        struct data d[n];  // Array of 'data' structures to store meeting information

        // Populate the 'd' array with the start, end, and position of each meeting
        for (int i = 0; i < n; i++) {
            d[i].start = start[i];
            d[i].end = end[i];
            d[i].pos = i + 1;  // Storing original position (1-based index)
        }

        // Sort meetings based on their end times using the custom comparator 'comp'
        sort(d, d + n, comp);

        // Initialize the counter for meetings that can be scheduled
        int cnt = 1;  // First meeting is always selected
        int freetime = d[0].end;  // Keep track of the end time of the last scheduled meeting
        vector<int> order;  // To store the order of meetings
        order.push_back(d[0].pos);  // Add the first meeting's position to the order

        // Iterate through the rest of the meetings
        for (int i = 1; i < n; i++) {
            // If the current meeting starts after the last scheduled meeting's end time
            if (d[i].start > freetime) {
                freetime = d[i].end;  // Update the free time to the end time of the current meeting
                order.push_back(d[i].pos);  // Add this meeting's position to the order
                cnt++;  // Increment the count of meetings
            }
        }

        return cnt;  // Return the maximum number of meetings that can be scheduled
    }
