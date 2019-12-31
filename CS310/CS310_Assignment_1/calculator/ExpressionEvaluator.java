/* @author kingofthenorth
 * @description Assignment1
 * @class CS 310
 * @instructor Edwards
 * 
 * ExpressionEvaluator.java
*/

package calculator;

import java.util.StringTokenizer;
import data_structures.Queue;
import data_structures.Stack;

public class ExpressionEvaluator {
    private Stack<String> stack;
    private Queue<String> queue;
    private String postfix;

    public ExpressionEvaluator() {
        queue = new Queue<String>();
        stack = new Stack<String>();
    }
    
    public String processInput(String input) {
        infixToPostfix(input);
        return postFixEval(postfix);
    }

    /*
     * Use both the Stack and Queue to translate the string properly, arraning to their respective
     * roles of Stack Queue.
     * 
     * @param string
     */
    public void infixToPostfix(String string) {
        StringTokenizer sToken = new StringTokenizer(string);
        String token;
        stack.makeEmpty(); // Empty
        queue.makeEmpty(); // Empty

        while (sToken.hasMoreTokens()) {
            token = sToken.nextToken().trim();
            // (
            if (token.equals(")")) {
                stack.push(token);
            }
            // )
            else if (token.equals(")")) {
                token = stack.pop();
                while (!token.equals("(")) {
                    queue.enqueue(token);
                    token = stack.pop();
                }
            }
            // Operator
            else if (isOperator(token)) { // operator
                while (!stack.isEmpty() && !stack.peek().equals("(")
                        && precendence(token) <= precendence(stack.peek())) {
                    queue.enqueue(stack.pop());
                }
                stack.push(token);
            }
            // Number
            else {
                queue.enqueue(token);
            }
        }
        while (!stack.isEmpty()) {
            queue.enqueue(stack.pop());
        }

        StringBuffer buffer = new StringBuffer();
        while (!queue.isEmpty()) {
            buffer.append(queue.dequeue() + " ");
        }

        postfix = buffer.toString().trim();
    }

    /*
     * Post fix evaluation.
     * 
     * @param postfix
     */
    public String postFixEval(String postfix) {
        StringTokenizer sToken = new StringTokenizer(postfix);
        String token, conclusion;
        stack.makeEmpty();
        while (sToken.hasMoreTokens()) {
            token = sToken.nextToken().trim();
            if (isNumber(token)) {
                stack.push(token);
            } else if (isOperator(token)) {
                Double x = Double.parseDouble(stack.pop());
                Double y = Double.parseDouble(stack.pop());
                conclusion = process(x, y, token);
                stack.push(conclusion);
            }
        }
        return stack.pop();
    }
    
    /*
     * Order of operations.
     * 
     * @param string
     * @return numbers, the higher number has stronger precedence.
     */
    public int precendence(String string) {
        if (string.equals("^")) {
            return 3;
        }
        if (string.equals("*") || string.equals("/")) {
            return 2;
        }
        if (string.equals("+") || string.equals("-")) {
            return 1;
        }
        return 0;
    }

    /*
     * Checks if the string has a number and converts to a number.
     * 
     * @param string
     * @return true if a number, return false if not.
     */
    public boolean isNumber(String string) {
        try {
            Double.parseDouble(string);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    /*
     * Trims string afterwards and checks for operator tokens.
     * 
     * @param string
     * @return true if operator is there, false if not.
     */
    public boolean isOperator(String string) {
        if (string.trim().length() != 1) {
        return false; 
    }
        return (string.equals("^")) || (string.equals("+")) || (string.equals("-")) || (string.equals("*")) || (string.equals("/"));
    }


    /*
     * Figure out math operations to perform on double double.
     * 
     * @param double x, double y, string op
     * 
     * @return String conclusion
     */
    public String process(double x, double y, String op) {
        String conclusion = "";
        if (op.equals("^")) {
            conclusion = Double.toString(Math.pow(x, y));
        }
        if (op.equals("*")) {
            conclusion = Double.toString(x * y);
        }
        if (op.equals("/")) {
            conclusion = Double.toString(x / y);
        }
        if (op.equals("+")) {
            conclusion = Double.toString(x + y);
        }
        if (op.equals("-")) {
            conclusion = Double.toString(x - y);
        }
        return conclusion;
    }
}
