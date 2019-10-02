/**

  * Ex2_1.java
  
  * Jill Oestreicher
  
  * CMPT 220

  * Lab 1

  * January 26, 2017
  
  * 1.8
  
  * This file contains problem 2.1 of Lab 1
  
*/

import java.util.Scanner; 

/**

  * Ex2_1
  
  * This class converts user input of celsius to fahrenheit
  
*/
public class Ex2_1 {
  public static void main(String[] args) {

    //variables declared, variable s of scanner class allows for input from user
    Scanner s = new Scanner(System.in);
    double celsius, fahrenheit;
    
    //takes celsius from user by assigning it to variable s
    System.out.println("Enter your degrees in celsius: ");
    celsius = s.nextDouble();
    
    //equation for converting celsius to fahrenheit, 9 is a double to ensure accuracy in conversion
    fahrenheit = (9.0/5) * celsius + 32;
    
    System.out.println(celsius + " in degrees fahrenheit is " + fahrenheit);
    
  }
}