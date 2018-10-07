import java.util.*;
import java.util.HashMap;
import java.util.Map;

public class Encoder{

  public static void main(String args[]){
    String[] arr1 = new String[]{"a"};
    String[] arr2 = new String[]{"1", "2", "3", "4"};
    String[] x = new String[arr1.length];
    x = encode(arr1,arr2);
    System.out.println(Arrays.toString(x));
  }


  public static String[] encode(String[] raw, String[] code_words) {
  
  Map<String,String> map = new HashMap<String,String>();
  String[] x = new String[raw.length];
  for(int i=0; i<raw.length;i++) {
    if(map.containsKey(raw[i])){
      x[i] = map.get(raw[i]);
      break;
    } else {
      map.put(raw[i],code_words[i]);
      x[i] = map.get(raw[i]);
    }
  }
  return x;
}


}

