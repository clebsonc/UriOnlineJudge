/*
In chats, it is very common among young people and adolescents use strings of letters, which often seem random to represent laughter. Some common examples are:

huaauhahhuahau
hehehehe
ahahahaha
jaisjjkasjksjjskjakijs
huehuehue

Claudia is a young programmer who was intrigued by the sound of "digital laughter." Some of them she can not even pronounce! But she realized that some of them seem better convey the feeling of laughter than others. The first thing she noticed is that the consonants do not interfere in how digital laughter influence the feeling of transmission. The second thing she noticed is that the funniest digital laughter are those in which the sequences of vowels are the same when read in the natural order (from left to right) or in reverse order (from right to left), ignoring consonants. For example, "hahaha" and "huaauhahhuahau" are among the funniest laughs while "riajkjdhhihhjak" and "huehuehue" are not among the funniest.

Claudia is very busy with the statistical analysis of digital laughter and asked for his help to write a program that determines, to a digital laugh, if she is the funniest or not.

Input

The input comprises a line containing a sequence of up to 50 characters, formed only by small letters without accent. Vowels are the letters 'a', 'e', 'i', 'o', 'u'. The sequence contains at least one vowel.

Output

Your program should produce a line containing a character, "S" if the laughter is of the funniest, or "N" otherwise.
*/

#include <iostream>
#include <string>

int main(){
  std::string s = "";
  std::cin >>  s;
  int i = 0, j=(int) s.size()-1;
  bool funny = true;
  while(i < s.size() && j>= 0){
    if((s.at(i) == 'a' || s.at(i) == 'e' || s.at(i) == 'i' || s.at(i) == 'o' || s.at(i) == 'u') &&
       (s.at(j) == 'a' || s.at(j) == 'e' || s.at(j) == 'i' || s.at(j) == 'o' || s.at(j) == 'u')){
      if(s.at(i) == s.at(j)){
        i++;
        j--;
      } else{
        funny = false;
        break;
      }
    }else if(s.at(i) == 'a' || s.at(i) == 'e' || s.at(i) == 'i' || s.at(i) == 'o' || s.at(i) == 'u'){
      j--;
    } else if(s.at(j) == 'a' || s.at(j) == 'e' || s.at(j) == 'i' || s.at(j) == 'o' || s.at(j) == 'u'){
      i++;
    } else{
      i++; 
      j--;
    }
  }
  std::cout << (funny ? "S" : "N") << std::endl;

  return 0;
}
