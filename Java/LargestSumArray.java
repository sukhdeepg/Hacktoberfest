// Kadane's Algorithm 
// This algorithm is use to find Largest Sum Contiguous Subarray.

import java.util.*;
import java.lang.*;
import java.io.*;

class MyClass {
    
	public static void main (String[] args) throws java.lang.Exception {
		
        int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
        int n=arr.length;
        int max=Integer.MIN_VALUE;
        int tmax=0;
        for(int i=0; i<n; i++)
        {
            arr[i]=ParseInt(sarr[i]);
            tmax+=arr[i];
            if(max<tmax)
                max=tmax;
            if(tmax<0)
                tmax=0;
        }
        System.out.println("Maximum Sum :"+max);
	}
}
