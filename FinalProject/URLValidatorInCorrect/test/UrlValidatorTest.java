

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing
	  
	   
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
	   //You can use this function for programming based testing

   }
   


}
