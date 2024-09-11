// Comparator function to sort jobs by profit in descending order
bool static comp(struct Job arr1, struct Job &arr2) {
    return arr1.profit > arr2.profit;  // Sort jobs by profit, with higher profit first
}

vector<int> JobScheduling(Job arr[], int n) 
{
    // Sort the array of jobs in descending order of profit
    sort(arr, arr + n, comp);

    int maxSch = 0;         // To track the maximum possible deadline
    int jobs = 0;           // To count the number of jobs scheduled
    long long mxprofit = 0;  // To accumulate the total profit

    // Find the maximum deadline (to define the schedule array size)
    for (int i = 0; i < n; i++)
        maxSch = max(maxSch, arr[i].dead);

    // Initialize a schedule array to keep track of the jobs scheduled at each time slot
    // The array is initialized with -1 (indicating that no job is scheduled yet)
    vector<int> sch(maxSch + 1, -1);

    // Iterate through each job in the sorted list
    for (int i = 0; i < n; i++) {
        int mover = arr[i].dead;  // Get the deadline of the current job

        // Try to schedule the job at the last possible slot before its deadline
        while (mover > 0) {
            // If the time slot is available (i.e., it's -1), schedule the job
            if (sch[mover] == -1) {
                sch[mover] = arr[i].id;  // Schedule the job at this time slot
                mxprofit += arr[i].profit;  // Add the job's profit to the total profit
                jobs++;  // Increment the job count
                break;  // Exit the loop after successfully scheduling the job
            }
            mover--;  // Move to the previous time slot if the current one is occupied
        }
    }

    // Return the total number of jobs scheduled and the total profit
    return {jobs, mxprofit};
}
