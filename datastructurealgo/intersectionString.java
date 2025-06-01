package datastructurealgo;

import java.util.ArrayList;
import java.util.Arrays;

public class intersectionString {// ***** leetcode 350
    public static void main(String[] args) {
        int nums1[] = {1, 2, 2, 1};
        int nums2[] = {2, 2,2};

        int res[] = intersectBruteForce(nums1, nums2);
        System.out.println("Without Map: " + Arrays.toString(res));
    }

    public static int[] intersectBruteForce(int[] nums1, int[] nums2) {
        ArrayList<Integer> result = new ArrayList<>();
        boolean[] used = new boolean[nums1.length]; // Track used elements

        for (int i = 0; i < nums2.length; i++) {
            for (int j = 0; j < nums1.length; j++) {
                if (!used[j] && nums2[i] == nums1[j]) {
                    result.add(nums2[i]);
                    used[j] = true; // Mark as used
                    break;
                }
            }
        }

        // Convert to int[]
        int[] res = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            res[i] = result.get(i);
        }

        return res;
    }
}
