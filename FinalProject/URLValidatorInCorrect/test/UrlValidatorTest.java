// UrlValidatorTest.java
//
// Ann Kostecki - kostecka
// Bridget McGinn - mcginnb
// Emily Stockenbojer - stockene
//

import junit.framework.TestCase;


//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {

   public void testManualTest()
   {
     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   System.out.println("Manual Tests:\n");

	   System.out.println("Expected False:");
	   System.out.println(urlVal.isValid("http://www.google.com:68853"));
	   System.out.println(urlVal.isValid("http:/www.google.com/test1")); //false
	   System.out.println(urlVal.isValid("http://www.google.com:65536"));
	   System.out.println(urlVal.isValid("http://www.google.com/.."));
	   System.out.println(urlVal.isValid("http:/www.google.com"));
	   System.out.println(urlVal.isValid("3ht://www.google.com"));
	   System.out.println(urlVal.isValid("http://256.256.256.256"));
	   System.out.println(urlVal.isValid("http://22288.12321.23423"));
	   System.out.println(urlVal.isValid("http:/"));
	   System.out.println(urlVal.isValid("http://aaa"));
	   System.out.println(urlVal.isValid("http:/256.256.256.256"));
	   System.out.println("\nExpected True:");
	   System.out.println(urlVal.isValid("http://www.google.com:65535"));
	   System.out.println(urlVal.isValid("http://www.google.com:65534"));
	   System.out.println(urlVal.isValid("http://www.google.com:605"));
	   System.out.println(urlVal.isValid("http://www.google.com:0"));
	   System.out.println(urlVal.isValid("http://www.google.com/test1/file")); //true
	   System.out.println(urlVal.isValid("http://www.google.com/test1/"));
	   System.out.println(urlVal.isValid("http://www.google.com"));
	   System.out.println(urlVal.isValid("www.google.com"));
	   System.out.println(urlVal.isValid("http://www.google.com?action=edit&mode=up"));
	   System.out.println(urlVal.isValid("http://www.google.com/test1")); //true
	   System.out.println(urlVal.isValid("http://255.255.255.255"));
	   System.out.println(urlVal.isValid("http://0.0.0.0"));
	   //System.out.println(urlVal.isValid("h3t://www.google.com"));
	   //System.out.println(urlVal.isValid("ftp://www.google.com"));
   }


   public void testScheme()
   {
	   UrlValidator urlTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   System.out.println("\nTesting Schemes...");


	   System.out.println("\nExpected True:");
	   System.out.println(urlTest.isValid("http://www.google.com"));
	   System.out.println(urlTest.isValid("www.google.com"));
	   //System.out.println(urlTest.isValid("ftp://www.google.com"));
	   //System.out.println(urlTest.isValid("https://www.google.com"));
	   //System.out.println(urlTest.isValid("h3t://www.google.com"));

	   System.out.println("\nExpected False:");
	   System.out.println(urlTest.isValid("http//www.google.com"));
	   System.out.println(urlTest.isValid("http:/www.google.com"));
	   System.out.println(urlTest.isValid("http/www.google.com"));
	   System.out.println(urlTest.isValid("http:www.google.com"));
	   System.out.println(urlTest.isValid(":www.google.com"));
	   System.out.println(urlTest.isValid(":/www.google.com"));
	   System.out.println(urlTest.isValid("://http:www.google.com"));
	   System.out.println(urlTest.isValid("3ht://www.google.com"));
	   System.out.println(urlTest.isValid("ftp:/www.google.com"));
	   System.out.println(urlTest.isValid("https:/www.google.com"));
	   System.out.println(urlTest.isValid("h3t:/www.google.com"));

   }

   public void testHost()
   {
	   UrlValidator urlTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   System.out.println("\nTesting Hosts...");

	   System.out.println("\nExpected True:");
	   System.out.println(urlTest.isValid("http://www.google.com"));
	   System.out.println(urlTest.isValid("http://google.com"));
	   System.out.println(urlTest.isValid("http://google.au"));
	   System.out.println(urlTest.isValid("http://123.com"));
	   System.out.println(urlTest.isValid("http://0.0.0.0"));
	   System.out.println(urlTest.isValid("http://www.google.com:80"));
	   System.out.println(urlTest.isValid("http://www.google.com:0"));
	   System.out.println(urlTest.isValid("http://255.255.255.255"));



	   System.out.println("\nExpected False:");
	   System.out.println(urlTest.isValid("http://"));
	   System.out.println(urlTest.isValid("http://google."));
	   System.out.println(urlTest.isValid("http://."));
	   System.out.println(urlTest.isValid("http://.com"));
	   System.out.println(urlTest.isValid("http://google.c"));
	   System.out.println(urlTest.isValid("http://google"));
	   System.out.println(urlTest.isValid("http://google.com:-1"));
	   System.out.println(urlTest.isValid("http://google.com:0a"));
	   System.out.println(urlTest.isValid("http://256.256.256.256"));


   }

   public void testPath()
   {
	   UrlValidator urlTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   System.out.println("\nTesting Paths...");

	   System.out.println("\nExpected True:");
	   System.out.println(urlTest.isValid("http://www.google.com/test/"));
	   System.out.println(urlTest.isValid("http://www.google.com/test"));
	   System.out.println(urlTest.isValid("http://www.google.com/test123"));
	   System.out.println(urlTest.isValid("http://www.google.com/test/test"));
	   System.out.println(urlTest.isValid("http://www.google.com/$123"));
	   System.out.println(urlTest.isValid("http://www.google.com/$123/"));
	   System.out.println(urlTest.isValid("http://www.google.com/$123/test"));
	   System.out.println(urlTest.isValid("http://www.google.com/test//test"));

	   System.out.println("\nExpected False:");
	   System.out.println(urlTest.isValid("http://www.google.com/#test"));
	   System.out.println(urlTest.isValid("http://www.google.com/#"));
	   System.out.println(urlTest.isValid("http://www.google.com/.."));
	   System.out.println(urlTest.isValid("http://www.google.com/../"));
	   System.out.println(urlTest.isValid("http://www.google.com/$123/test"));
	   System.out.println(urlTest.isValid("http://www.google.com/../test"));

   }

   public void testQuery()
   {
	   UrlValidator urlTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   System.out.println("\nTesting Queries...");

	   System.out.println("\nExpected True:");
	   System.out.println(urlTest.isValid("http://www.google.com"));
	   System.out.println(urlTest.isValid("http://www.google.com?test=test"));
	   System.out.println(urlTest.isValid("http://www.google.com?test=test&test=test"));
   }


   public void testIsValid()
   {

      //scheme + authority + port + path + query
      System.out.println("Unit testing");
      String[] trueScheme = {"http://", "ftp://", ""};
      String[] falseScheme = {"3ht://", "http:/", "http:"};
      String[] trueAuthority = {"go.com", "go.au", "0.0.0.0"};
      String[] falseAuthority = {"1.2.3.4.5", "go.a", "aaa."};
      String[] truePort = {":80", ":65535", ":0"};
      String[] falsePort = {":-1", ":65636", ":65a"};
      String[] truePath = {"/test1", "/t123", ""};
      String[] falsePath = {"/..", "/../", "test1//file"};
      String[] trueQuery = {"?action=view", "?action=edit&mode=up", ""};

      String testURL = trueScheme[1] + trueAuthority[0] + truePort[0] + truePath[0] + trueQuery[0];
      System.out.println();
      System.out.println("Expecting true");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = trueScheme[s] + trueAuthority[a] + truePort[po] + truePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }

      System.out.println();
      System.out.println("Expecting false");

      System.out.println();
      System.out.println("False Scheme");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = falseScheme[s] + trueAuthority[a] + truePort[po] + truePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }

      System.out.println();
      System.out.println("False Authority");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = trueScheme[s] + falseAuthority[a] + truePort[po] + truePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }

      System.out.println();
      System.out.println("False Port");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = trueScheme[s] + trueAuthority[a] + falsePort[po] + truePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }

      System.out.println();
      System.out.println("False Path");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = trueScheme[s] + trueAuthority[a] + truePort[po] + falsePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }

      System.out.println();
      System.out.println("False Scheme + Authority");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = falseScheme[s] + falseAuthority[a] + truePort[po] + truePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }

      System.out.println();
      System.out.println("False Scheme + Authority + Port");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = falseScheme[s] + falseAuthority[a] + falsePort[po] + truePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }

      System.out.println();
      System.out.println("False Scheme + Authority + Port + Path");
      System.out.println();

      for(int s = 0; s<3; s++){
         for(int a = 0; a<3; a++){
            for(int po = 0; po<3; po++){
               for(int pa = 0; pa<3; pa++){
                  for(int q = 0; q<3; q++){
                     testURL = falseScheme[s] + falseAuthority[a] + falsePort[po] + falsePath[pa] + trueQuery[q];
                     UrlValidator x = new UrlValidator();
                     boolean y = x.isValid(testURL);
                     System.out.println(y + " " + testURL);
                  }
               }
            }
         }
      }
   }



   public static void main(String [] args) {
	   UrlValidatorTest z = new UrlValidatorTest();
	   z.testIsValid();
   }



}
