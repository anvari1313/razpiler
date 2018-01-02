import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Converter {
    public static String convert(String input) {
        String result = new String();
        char c;
        for (int i = 0; i < input.length(); i++) {
            c = input.charAt(i);
            switch (c)
            {
                case 'آ':
                    result += 'A';
                    break;
                case 'ا':
                    result += 'B';
                    break;
                case 'ب':
                    result += 'C';
                    break;
                case 'پ':
                    result += 'D';
                    break;
                case 'ت':
                    result += 'E';
                    break;
                case 'ث':
                    result += 'F';
                    break;
                case 'ج':
                    result += 'G';
                    break;
                case 'چ':
                    result += 'H';
                    break;
                case 'ح':
                    result += 'I';
                    break;
                case 'خ':
                    result += 'J';
                    break;
                case 'د':
                    result += 'K';
                    break;
                case 'ذ':
                    result += 'L';
                    break;
                case 'ر':
                    result += 'M';
                    break;
                case 'ز':
                    result += 'N';
                    break;
                case 'ژ':
                    result += 'O';
                    break;
                case 'س':
                    result += 'P';
                    break;
                case 'ش':
                    result += 'Q';
                    break;
                case 'ص':
                    result += 'R';
                    break;
                case 'ض':
                    result += 'S';
                    break;
                case 'ط':
                    result += 'T';
                    break;
                case 'ظ':
                    result += 'U';
                    break;
                case 'ع':
                    result += 'V';
                    break;
                case 'غ':
                    result += 'W';
                    break;
                case 'ف':
                    result += 'X';
                    break;
                case 'ق':
                    result += 'Y';
                    break;
                case 'ک':
                    result += 'Z';
                    break;
                case 'گ':
                    result += 'a';
                    break;
                case 'ل':
                    result += 'b';
                    break;
                case 'م':
                    result += 'c';
                    break;
                case 'ن':
                    result += 'd';
                    break;
                case 'و':
                    result += 'e';
                    break;
                case 'ه':
                    result += 'f';
                    break;
                case 'ی':
                    result += 'g';
                    break;
                case '۰':
                    result += '0';
                    break;
                case '۱':
                    result += '1';
                    break;
                case '۲':
                    result += '2';
                    break;
                case '۳':
                    result += '3';
                    break;
                case '۴':
                    result += '4';
                    break;
                case '۵':
                    result += '5';
                    break;
                case '۶':
                    result += '6';
                    break;
                case '۷':
                    result += '7';
                    break;
                case '۸':
                    result += '8';
                    break;
                case '۹':
                    result += '9';
                    break;
                case '،':
                    result += ',';
                    break;
                case '؛':
                    result += ';';
                    break;
                default:
                    result += c;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        try {
            FileWriter f = new FileWriter(args[1]);
            Scanner s = new Scanner(new File(args[0]));
            while (s.hasNextLine())
            {
                f.write(convert(s.nextLine()) + '\n');
//                System.out.println(convert(s.nextLine()));
            }
            f.close();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
