# priority scheduling

```c
#include<stdio.h>
struct process
{
  char process_name;
  int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;int status;
}
process_queue[10];
int limit;
void Arrival_Time_Sorting()
{
  struct process temp;
  int i, j;
  for(i = 0; i < limit - 1; i++)
  {
    for(j = i + 1; j < limit; j++)
    {
      if(process_queue[i].arrival_time > process_queue[j].arrival_time)
      {
        temp = process_queue[i];
        process_queue[i] = process_queue[j];
        process_queue[j] = temp;
      }
    }
  }
}
void main()
{
  int i, time = 0, burst_time = 0, largest;
  char c;
  float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
  printf("\nEnter Total Number of Processes:\t");
  scanf("%d", &limit);
  for(i = 0, c = 'A'; i < limit; i++, c++)
  {
    process_queue[i].process_name = c;
    printf("\nEnter Details For Process[%C]:\n", 
    process_queue[i].process_name);
    printf("Enter Arrival Time:\t");
    scanf("%d", &process_queue[i].arrival_time );
    printf("Enter Burst Time:\t");
    scanf("%d", &process_queue[i].burst_time);
    printf("Enter Priority:\t");
    scanf("%d", &process_queue[i].priority);
    process_queue[i].status = 0;
    burst_time = burst_time + process_queue[i].burst_time;
  }
  Arrival_Time_Sorting();
  process_queue[9].priority = -9999;
  printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
  for(time = process_queue[0].arrival_time; time < burst_time;)
  {
    largest = 9;
    for(i = 0; i < limit; i++)
    {
      if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
      {
        largest = i;
      }
    }
    time = time + process_queue[largest].burst_time;
    process_queue[largest].ct = time;
    process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arrival_time - process_queue[largest].burst_time;
    process_queue[largest].turnaround_time = process_queue[largest].ct - process_queue[largest].arrival_time;
    process_queue[largest].status = 1;
    wait_time = wait_time + process_queue[largest].waiting_time;
    turnaround_time = turnaround_time + 
    process_queue[largest].turnaround_time;
    printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].arrival_time, process_queue[largest].burst_time,process_queue[largest].priority, process_queue[largest].waiting_time);
  }
  average_waiting_time = wait_time / limit;
  average_turnaround_time = turnaround_time / limit;
  printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
  printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
}
```

# priority non preemptive scheduling

```c
#include<stdio.h>
int main()
{
  int burst_time[20], process[20], waiting_time[20],turnaround_time[20], priority[20];
  int i, j, limit, sum = 0, position, temp;
  float average_wait_time, average_turnaround_time;
  printf("Enter Total Number of Processes:\t");
  scanf("%d", &limit);
  printf("\nEnter Burst Time and Priority For %d Processes\n", limit);
  for(i = 0; i < limit; i++)
  {
    printf("\nProcess[%d]\n", i + 1);
    printf("Process Burst Time:\t");
    scanf("%d", &burst_time[i]);
    printf("Process Priority:\t");
    scanf("%d", &priority[i]);
    process[i] = i + 1;
  }
  for(i = 0; i < limit; i++)
  {
    position = i;
    for(j = i + 1; j < limit; j++)
    {
      if(priority[j] < priority[position])
      {
        position = j;
      }
    }
    temp = priority[i];
    priority[i] = priority[position];
    priority[position] = temp; 
    temp = burst_time[i];
    burst_time[i] = burst_time[position];
    burst_time[position] = temp;
    temp = process[i];
    process[i] = process[position];
    process[position] = temp;
  }
  waiting_time[0] = 0;
  for(i = 1; i < limit; i++)
  {
    waiting_time[i] = 0;
    for(j = 0; j < i; j++)
    {
      waiting_time[i] = waiting_time[i] + burst_time[j];
    }
    sum = sum + waiting_time[i];
  }
  average_wait_time = sum / limit;
  sum = 0;
  printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
  for(i = 0; i < limit; i++)
  {
    turnaround_time[i] = burst_time[i] + waiting_time[i];
    sum = sum + turnaround_time[i];
    printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], 
    burst_time[i], waiting_time[i], turnaround_time[i]);
  }
  average_turnaround_time = sum / limit;
  printf("\nAverage Waiting Time:\t%f", average_wait_time);
  printf("\nAverage Turnaround Time:\t%f\n", 
  average_turnaround_time);
  return 0;
}
```

# FCFS

```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  
#include <pthread.h> 


int main(int argc, char const *argv[])
{
    printf("\n19BCE2250 - Ishan Jogalekar");
    int range, queue_size, cur_pos, cur_seek_time, total_seek_time = 0;
    printf("\nEnter the size of disk : ");
    scanf("%d", &range);
    printf("\nEnter the number requests : ");
    scanf("%d", &queue_size);

    int req_queue[queue_size];
    printf("\nEnter the requests : ");
    for (int i = 0; i < queue_size; i++)
    {
        scanf("%d ", &req_queue[i]);
    }
    int hold;
    scanf("%d", &hold);
    printf("\nEnter the  head position : ");
    scanf("%d", &cur_pos);
    for (int i = 0; i < queue_size; i++)
    {
        cur_seek_time = abs(req_queue[i] - cur_pos);
        printf("\nDisk head moves from %d to %d with seek time %d", cur_pos, req_queue[i], cur_seek_time);
        cur_pos = req_queue[i];
        total_seek_time += cur_seek_time;
    }
    printf("\nTotal Seek Time is : %d", total_seek_time);
    return 0;
}
```


# FIFO
```c
#include<stdio.h>
 
int main()
{
      printf("19BCE2250 - Ishan Jogalekar");
      int reference_string[10], page_faults = 0, m, n, s, pages, frames;
      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pages);
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No. [%d]:\t", m + 1);
            scanf("%d", &reference_string[m]);
      }
      printf("\nEnter Total Number of Frames:\t");
      {
            scanf("%d", &frames);
      }
      int temp[frames];
      for(m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            s = 0;
            for(n = 0; n < frames; n++)
            {
                  if(reference_string[m] == temp[n])
                  {
                        s++;
                        page_faults--;
                  }
            }     
            page_faults++;
            if((page_faults <= frames) && (s == 0))
            {
                  temp[m] = reference_string[m];
            }   
            else if(s == 0)
            {
                  temp[(page_faults - 1) % frames] = reference_string[m];
            }
            printf("\n");
            for(n = 0; n < frames; n++)
            {     
                  printf("%d\t", temp[n]);
            }
      } 
      printf("\nTotal Page Faults:\t%d\n", page_faults);
      return 0;
}
```


# LRU
```c
#include<stdio.h>
 
int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}
 
int main()
{
    printf("\n 19BCE2250 - Ishan Jogalekar");
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("\nEnter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("\nEnter number of pages: ");
    scanf("%d", &no_of_pages);
    printf("\nEnter reference string: ");
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == -1){
                counter++;
                faults++;
                frames[j] = pages[i];
                time[j] = counter;
                flag2 = 1;
                break;
               }
            }  
        }
        if(flag2 == 0){
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        printf("\n");
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    printf("\nTotal Page Faults = %d", faults);
    return 0;
}
```

# SCAN

```c
#include<stdio.h>
int main()
{
    printf("\n19BCE2250 - Ishan Jogalekar");
    int i,j,sum=0,n;
    int d[20];
    int disk,temp,max,dloc; 
    printf("\nEnter number of location:");
    scanf("%d",&n);
    printf("\nEnter position of head:");
    scanf("%d",&disk);
    printf("\nenter elements of disk queue:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
    }
    d[n]=disk; 
    n=n+1;
    for(i=0;i<n;i++) 
    {
        for(j=i;j<n;j++)
        {
            if(d[i]>d[j])
            {
                temp=d[i];
                d[i]=d[j];
                d[j]=temp;
            }
        }
    }
    max=d[n];
    for(i=0;i<n;i++) 
    {
        if(disk==d[i]) { dloc=i; break; }
    }
    for(i=dloc;i>=0;i--)
    {
        printf("%d -->",d[i]);
    }
    printf("0 -->");
    for(i=dloc+1;i<n;i++)
    {
        printf("%d-->",d[i]);
    }
    sum=disk+max;
    printf("\nmovement of total cylinders %d",sum);
    return 0;
}
```

# SSFT

```c
#include<stdio.h>
 
struct head
{
      int num;
      int flag;
};
 
int main()
{
      printf("\n 19BCE2250 - Ishan Jogalekar");
      struct head h[33];
      int array_1[33], array_2[33];
      int count = 0, j, x, limit, minimum, location, disk_head, sum = 0;
      printf("\nEnter total number of locations:\t");
      scanf("%d", &limit);
      printf("\nEnter position of disk head:\t");
      scanf("%d", &disk_head);
      printf("\nEnter elements of disk head queue\n");
      while(count < limit)
      {
            scanf("%d", &h[count].num);   
            h[count].flag = 0;
            count++;
      }
      for(count = 0; count < limit; count++)
      {                 
            x = 0; 
            minimum = 0;
            location = 0;
            for(j = 0; j < limit; j++)
            {
                  if(h[j].flag == 0)
                  {
                        if(x == 0)
                        {
                              array_1[j] = disk_head - h[j].num;
                              if(array_1[j] < 0)
                              { 
                                    array_1[j] = h[j].num - disk_head;
                              }
                              minimum = array_1[j];
                              location = j;
                              x++; 
                        }
                        else
                        {
                              array_1[j] = disk_head - h[j].num;
                              if(array_1[j] < 0)
                              { 
                                    array_1[j] = h[j].num - disk_head;
                              }
                        }
                        if(minimum > array_1[j])
                        { 
                              minimum = array_1[j]; 
                              location = j;
                        }
                  }
            }
            h[location].flag = 1;
            array_2[count] = h[location].num - disk_head;
            if(array_2[count] < 0)
            {
                  array_2[count] = disk_head - h[location].num;
            }
            disk_head = h[location].num;
      }
      count = 0;
      while(count < limit)
      {
            sum = sum + array_2[count];      
            count++;
      }
      printf("\nTotal movements of the cylinders:\t%d", sum);
      return 0;
}
```