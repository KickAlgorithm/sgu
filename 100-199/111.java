/*******************************************************
                111. Very simple problem
 
 
                time limit per test: 0.25 sec.
                memory limit per test: 4096 KB
 
 You are given natural number X. Find such maximum integer number that it square is not greater than X.
 
 Input
 
 Input file contains number X (1≤X≤101000).
 
 Output
 
 Write answer in output file.
 
 Sample Input
 
 16
 Sample Output
 
 4
 ******************************************************/

import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        BigInteger l = new BigInteger("1");
        BigInteger r = (new BigInteger("10")).pow(500);
        BigInteger one = new BigInteger("1");
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        BigInteger x = cin.nextBigInteger();
        BigInteger mid,ans;
        ans = new BigInteger("1");
        while(true){
            mid = (l.add(r)).shiftRight(1);
            if( (mid.pow(2)).compareTo(x) > 0){
                r = mid.subtract(one);
            }else{
                ans = mid;
                l = mid.add(one);
            }
            if(l.compareTo(r) > 0)
                break;
        }
        System.out.println(ans);
    }
}