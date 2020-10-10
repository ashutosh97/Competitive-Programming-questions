class main {

    public static void main(String[] args){

        System.out.println(reverseChars("These Chars will be in reverse"));

        }

    public static String reverseChars(String reverseIt) {

        int stringLength;
        String itReversed;

        reverseIt = reverseIt;

        stringLength = reverseIt.length();
        itReversed = "";

        for (int i = 1; i <= stringLength; i++){
            char backwardChars = reverseIt.charAt(stringLength - i);

            itReversed += backwardChars;
        }
        return itReversed;
    }
        }