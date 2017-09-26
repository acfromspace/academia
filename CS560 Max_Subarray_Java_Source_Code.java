// SDSU CS 560
// Algorithms
// Maximum Subarray Problem
// Java Source Code

class indexAndSumTriple {
    int low;
    int high;
    int sum;
}

public class maximumSubarrayProblem {
    static final int INFINITY = 9999;

    static indexAndSumTriple findMaxStraddleSubarray(int[] A, int low, int mid, int high) {
        int leftSum = -INFINITY; // 9999 plays the role of "infinity"
        int sum = 0;
        int maxLeft = 0;
        for (int i = mid; i >= low; i--) {
            sum = sum + A[i];
            if (sum > leftSum) {
                leftSum = sum;
                maxLeft = i;
            }
        }
        int rightSum = -INFINITY; // 9999 plays the role of "infinity"
        sum = 0;
        int maxRight = 0;
        for (int j = mid + 1; j <= high; j++) {
            sum = sum + A[j];
            if (sum > rightSum) {
                rightSum = sum;
                maxRight = j;
            }
        }
        indexAndSumTriple returnValues = new indexAndSumTriple();
        returnValues.low = maxLeft;
        returnValues.high = maxRight;
        returnValues.sum = leftSum + rightSum;
        return returnValues;
    }

    static indexAndSumTriple findMaximumSubarray(int[] A, int low, int high) {
        if (high == low) {
            indexAndSumTriple returnValues = new indexAndSumTriple();
            returnValues.low = low;
            returnValues.high = high;
            returnValues.sum = A[low];
            return returnValues;
        } else {
            int mid = (low + high) / 2;
            indexAndSumTriple left = findMaximumSubarray(A, low, mid);
            indexAndSumTriple right = findMaximumSubarray(A, mid + 1, high);
            indexAndSumTriple straddle = findMaxStraddleSubarray(A, low, mid, high);
            if ((left.sum >= right.sum) && (left.sum >= straddle.sum)) {
                indexAndSumTriple returnValues = new indexAndSumTriple();
                returnValues.low = left.low;
                returnValues.high = left.high;
                returnValues.sum = left.sum;
                return returnValues;
            } else
            if ((right.sum >= left.sum) && (right.sum >= straddle.sum)) {
                indexAndSumTriple returnValues = new indexAndSumTriple();
                returnValues.low = right.low;
                returnValues.high = right.high;
                returnValues.sum = right.sum;
                return returnValues;
            } else {
                indexAndSumTriple returnValues = new indexAndSumTriple();
                returnValues.low = straddle.low;
                returnValues.high = straddle.high;
                returnValues.sum = straddle.sum;
                return returnValues;
            }
        }
    }

    public static void main() {
        int[] data = new int[17];
        data[1] = 13;
        data[2] = -3;
        data[3] = -25;
        data[4] = 20;
        data[5] = -3;
        data[6] = -16;
        data[7] = -23;
        data[8] = 18;
        data[9] = 20;
        data[10] = -7;
        data[11] = 12;
        data[12] = -5;
        data[13] = -22;
        data[14] = 15;
        data[15] = -4;
        data[16] = 7;
        indexAndSumTriple answer;
        answer = findMaximumSubarray(data, 1, 16);
        System.out.println("Low = " + answer.low +
            " High = " + answer.high +
            " Sum = " + answer.sum);
        return;
    }
}

// Low = 8 High = 11 Sum = 43