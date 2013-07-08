/*
# Anand Rathi Confidential - OCO Source Materials 
# (C) Copyright Anand Prakash Rathi & Aarti Anand Rathi. 2008, 2012 
# The source code for this program is not published or otherwise divested of its trade secrets, 
# irrespective of what has been deposited with the U.S. Copyright Office.
 * /home/anandrathi/sre/libcdr/cppdb/Fstring.cpp
*/

#include <iostream>
#include <string>
#include "Fstring.h"
#include <assert.h>
#include <map>
#include <vector>
#include <time.h>

void test_Craete0lenstr()
{
	fixedstring str;
	int ilen =  str.size();
	std::cout << "Len= [" << ilen << "]\n";
	std::cout << "Data = [" << str.data() << "]\n";
	assert(ilen ==0);
}

void test_CraeteFromCstr()
{
	fixedstring str("Hello world!");
	int ilen =  str.size();
	std::cout << "Len= [" << ilen << "]\n";
	std::cout << "Data = [" << str.data() << "]\n";
	assert(ilen ==12);
}

void test_CraeteFromChar()
{
	fixedstring str(1,'a');
	int ilen =  str.size();
	std::cout << "Len= [" << ilen << "]\n";
	std::cout << "Data = [" << str.data() << "]\n";
	assert(ilen ==1);
}

void test_CraeteFromNChar()
{
	fixedstring str(255, 'a');
	int ilen =  str.size();
	std::cout << "Len= [" << ilen << "]\n";
	std::cout << "Data = [" << str.data() << "]\n";
	assert(ilen ==255);
}

void test_CraeteCompareCstr()
{
	char * p = "hello World";
	fixedstring str(p);
	int ilen =  str.size();
	std::cout << "Len= [" << ilen << "]\n";
	std::cout << "Data = [" << str.data() << "]\n";
	int compare1 = str.compare(p);
	if(p==str)
	{
		std::cout << " p==str Compare ok\n";
	}

	if(str==p)
	{
		std::cout << "str==p Compare ok\n";
	}
	if(str==p)
	{
		std::cout << "str==p Compare ok\n";
	}

}

void test_CraeteCompareLessMore()
{
	char * ap = "a";
	char * aap = "aa";
	char * bp = "b";
	char * bbp = "bb";
	fixedstring astr(ap);
	fixedstring aastr(aap);
	fixedstring bstr(bp);
	fixedstring bbstr(bbp);

	if(astr<aastr)
	{
		std::cout << " astr<aastr ok\n";
	} else
		std::cout << " astr<aastr Not ok\n";

	if(ap<aastr)
	{
		std::cout << " ap<aastr ok\n";
	} else
		std::cout << " ap<aastr Not ok\n";

	if(astr<aap)
	{
		std::cout << " astr<aap ok\n";
	} else
		std::cout << " astr<aap Not ok\n";

		
	//////////////////////////////////////////////////////////
	if(astr<=aastr)
	{
		std::cout << " astr<=aastr ok\n";
	} else
		std::cout << " astr<=aastr Not ok\n";

	if(ap<=aastr)
	{
		std::cout << " ap<=aastr ok\n";
	} else
		std::cout << " ap<=aastr Not ok\n";

	if(astr<=aap)
	{
		std::cout << " astr<=aap ok\n";
	} else
		std::cout << " astr<=aap Not ok\n";

		
	//////////////////////////////////////////////////////////

	if(astr<bstr)
	{
		std::cout << " astr<bstr ok\n";
	} else
		std::cout << " astr<bstr Not ok\n";

	if(ap<bstr)
	{
		std::cout << " ap<bstr ok\n";
	} else
		std::cout << " ap<bstr Not ok\n";

	//////////////////////// > //////////////////////////////////

	if(aastr>astr)
	{
		std::cout << " aastr>astr ok\n";
	} else
		std::cout << " aastr>astr  Not ok\n";

	if(aap>astr)
	{
		std::cout << " aap>astr ok\n";
	} else
		std::cout << " aap>astr Not ok\n";

	if(astr>aap)
	{
		std::cout << " astr>aap ok\n";
	} else
		std::cout << " astr>aap Not ok\n";

	////////////////////////// >= ////////////////////////////////

	if(aastr>=aastr)
	{
		std::cout << " aastr>=aastr ok\n";
	} else
		std::cout << " aastr>=aastr  Not ok\n";
	
	if(aastr>=aap)
	{
		std::cout << " aastr>=aap ok\n";
	} else
		std::cout << " aastr>=aap  Not ok\n";

	if(aap>=aastr)
	{
		std::cout << " aap>=aastr ok\n";
	} else
		std::cout << " aap>=aastr  Not ok\n";


	if(aastr>=astr)
	{
		std::cout << " aastr>=astr ok\n";
	} else
		std::cout << " aastr>=astr  Not ok\n";

	if(aap>=astr)
	{
		std::cout << " aap>=astr ok\n";
	} else
		std::cout << " aap>=astr Not ok\n";

	if(bstr>=aap)
	{
		std::cout << " astr>=aap ok\n";
	} else
		std::cout << " astr>=aap Not ok\n";


}

//
void test_CraeteStrMap()
{
	std::vector<std::string> vstr ; 
	char * p[] = { "a" , "b" , "c" , "d", "e", "f", "g", "h", "i", "j", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" } ;
	vstr.push_back("a"); 
	vstr.push_back("b") ;
	vstr.push_back("c") ;
	vstr.push_back("d") ;
	vstr.push_back("e") ;
	vstr.push_back("f") ;
	vstr.push_back("g") ;
	vstr.push_back("h") ;
	vstr.push_back("i") ;
	vstr.push_back("j") ;
	vstr.push_back("j") ;
	vstr.push_back("k") ;
	vstr.push_back("l") ;
	vstr.push_back("m") ;
	vstr.push_back("n") ;
	vstr.push_back("o") ;
	vstr.push_back("p") ;
	vstr.push_back("q") ;
	vstr.push_back("r") ;
	vstr.push_back("s") ;
	vstr.push_back("t") ;
	vstr.push_back("u") ;
	vstr.push_back("v") ;
	vstr.push_back("w") ;
	vstr.push_back("x") ;
	vstr.push_back("y") ;
	vstr.push_back("z") ;
	
	clock_t startTime = clock();
	
	std::map< fixedstring, fixedstring > mapfstr; 
	std::vector<std::string>::iterator it =  vstr.begin();
	for(it =  vstr.begin() ;it!=vstr.end();it++)
	{
		mapfstr[it->data()] = it->data();
	}

	for(it =  vstr.begin() ;it!=vstr.end();it++)
	{
		std::map< fixedstring, fixedstring >::iterator mit = mapfstr.find(it->data()) ;
		if( mit!=mapfstr.end() )
		{
//			/std::cout << "found :=" << mit->second.data() << "\n"; 
		}
		else
		{
			std::cout << "Not found :=" << mit->second.data() << "\n"; 
		}
	}
	
}

void test_CraeteFSTRMap()
{
	std::vector<std::string> vstr ; 
	char p[270] ={0}; 
	
	clock_t startTime = clock();
//9000,000
	for(unsigned long i = 0 ; i< 5000000; i++)
	{
		sprintf(p,"%0165d",i);
		vstr.push_back(p); 
	}
	std::cout << "Test size = = " <<  vstr.size() << "\n";
	std::vector<std::string>::iterator it =  vstr.begin();
	{
		std::map< std::string, std::string > mapstdstr; 
		std::map< std::string, std::string >::iterator sit  ; 
		clock_t startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			mapstdstr[it->data()] = it->data();
		}
		std::cout << "std::string key val Map Insertion time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";
		startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			sit  = mapstdstr.find(it->data());
		}
		std::cout << "std::string key val Map Search time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";
		startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			sit  = mapstdstr.find(it->data());
			sit->second = "a";
			sit->second = it->data();
			sit->second = "a";
			sit->second = it->data();
		}
		std::cout << "std::string key val Map Replace time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";


		
	}
	{
		typedef Fixbasic_string<char,166> f10str;
		
		
		std::map< f10str, f10str> mapfstr; 
		std::map< f10str, f10str>::iterator sit;
		clock_t startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			mapfstr[it->data()] = it->data();
		}
		std::cout << "fixedstring key val Map Insertion time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";
		startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			mapfstr.find(it->data());
		}
		std::cout << "fixedstring key val Map Search time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";

		startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			sit  = mapfstr.find(it->data());
			sit->second = "a";
			sit->second = it->data();
			sit->second = "a";
			sit->second = it->data();
			//mapfstr[it->data()] = "a";
		}
		std::cout << "fixedstring key val Map Replace  time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";

	}
	
	
	{
		std::map< std::string, char> mapstdstr; 
		clock_t startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			mapstdstr[it->data()] = 0;
		}
		std::cout << "std::string key , char val Map Insertion time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";
		startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			mapstdstr.find(it->data());
		}
		std::cout << "std::string Map key , char val Search time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";
		
	}
	{
		typedef Fixbasic_string<char,10> f10str;
		std::map< f10str, char> mapfstr; 
		clock_t startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			mapfstr[it->data()] = 0;
		}
		std::cout << "fixedstring key , char val MapInsertion time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";
		startTime = clock();
		for(it =  vstr.begin() ;it!=vstr.end();it++)
		{
			mapfstr.find(it->data());
		}
		std::cout << "fixedstring key , char val Map Search time = " <<  (clock() - startTime)/ CLOCKS_PER_SEC << "\n";
	}
	

}


void testFstringALl(void)
{

test_Craete0lenstr();

test_CraeteFromCstr();

test_CraeteFromChar();

test_CraeteFromNChar();

test_CraeteCompareCstr();

test_CraeteCompareLessMore();

test_CraeteStrMap();

test_CraeteFSTRMap();

}