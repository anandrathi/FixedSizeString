/*
# Anand Rathi Confidential - OCO Source Materials 
# (C) Copyright Anand Prakash Rathi & Aarti Anand Rathi. 2008, 2012 
# The source code for this program is not published or otherwise divested of its trade secrets, 
# irrespective of what has been deposited with the U.S. Copyright Office.
*/

#ifndef _FSTRING_H
#define _FSTRING_H

#include <string.h>
#include <stdexcept>
#include <iostream>

  template<typename _CharT , int _sizeT = 255>
    class Fixbasic_string
    {
		
      // Types:
    public:
		typedef unsigned int size_type;
		
	protected:
		size_type _size ;
		_CharT _p[_sizeT+1]; 
		
		void _copy( const _CharT *__s, size_type __n )
		{
			if(__n<0)
			   return;
			if(__n>_sizeT)
			   __n=_sizeT;
			_size=__n;
			for(size_type i = 0; i<__n; ++i)
			{
				this->_p[i]=__s[i];
			}
			//memcpy(this->data(), __s, __n * sizeof(_CharT));
			this->_p[_size]=0;
		}

		void _append( const _CharT *__s, size_type __n =0)
		{
			if(__n<0)
			   return;
			if(__n==0)
				__n=strlen(__s);
			if(__n+_size >_sizeT)
			{
				__n=_sizeT-_size;
			}
			if(__n>0 && __n< _sizeT)
			{
				//memcpy(this->data()+_size, __s, __n * sizeof(_CharT));
				int j=0;
				for(size_type i=_size ;i<__n+_size;++i,++j)
				{
					this->_p[i] = __s[j];
				}
			}
			_size+=__n;
			this->_p[_size]=0;
		}
		
		void _append( _CharT __s, size_type __n =1)
		{
			if(__n<0)
			   return;
			if(__n+_size >_sizeT)
			{
				__n=_sizeT-_size;
			}
			if(__n>0 && __n< _sizeT)
			{
				for(size_type i=_size;i<__n+_size;++i)
				{
					this->_p[i] = __s;
				}
				_size+=__n;
				this->_p[_size]=0;
			}
		}
	

		
    public:

      size_type
      size() const
      { 
		  return _size; 
	  }

	_CharT * data() 
	{
		return _p;
	}
	const _CharT * data() const
	{
		return _p;
	}
	int compare(const _CharT *__rhs , size_type __n =0) const
	{
		if(__n ==0)
		   __n=_sizeT;
			//__n = strlen(__rhs );
		if(__n>_sizeT)
		   __n=_sizeT;
		int __r = ::strncmp(this->data(), __rhs  , __n);
		//std::cout << "int [" << __r << "] compare(const _CharT * __s[" << __rhs  << "] n=[" << __n << "]\n";
		return __r;
	}

    int compare( const Fixbasic_string& __str) const
      {
		int __n = __str.size();
		if(__n>_sizeT)
		   __n=_sizeT;
		int __r = ::strncmp( (char*)this->data(), ( char *)__str.data(),_sizeT );
		//std::cout  << "this =[" << this->data() << "] " <<    "int [" << __r << "] compare(Fixbasic_string& data [" << __str.data() << "] n=[" << _sizeT << "]\n";
		return __r;
      }

  /**
   *  @brief  Default constructor creates an empty string.
   */
	Fixbasic_string()
	{
		_size=0;
		data()[0]=0;
		data()[_sizeT]=0;
		
	}

	  /**
	   *  @brief  Construct string with copy of value of @a str.
	   */
	  Fixbasic_string(const Fixbasic_string& __rhsstr)
	  {
		 _size=0 ;
		_copy( __rhsstr.data(),__rhsstr.size());
		_p[_sizeT]=0;
	  }
      /**
       *  @brief  Construct string as copy of a substring.
       */
	   Fixbasic_string(const Fixbasic_string& __rhsstr, size_type __pos, size_type __n = _sizeT)
	   {
		 _size=0 ;
		  _p[_sizeT]=0;
		  _copy(__rhsstr.data() + __pos, __n);
	   }

      /**
       *  @brief  Construct string initialized by a character %array.
       */
      Fixbasic_string(const _CharT* __s, size_type __n )
	  {
		 _size=0 ;
		  _copy(__s, __n);
		  _p[_sizeT]=0;
	  }
      /**
       *  @brief  Construct  zstr.
       */
      Fixbasic_string(const char* __s )
	  {
		 _size=0 ;
		  _copy(__s, strlen(__s));
		  _p[_sizeT]=0;
	  }

      /**
       *  @brief  Construct string as copy o
	   
      /**
       *  @brief  Construct string as multiple characters.
       */
      Fixbasic_string(size_type __n, _CharT __c)
      {
			_size=0 ;
			_p[_sizeT]=0;
			if(__n > _sizeT)
				__n = _sizeT;
			_size=__n ;
			for(size_type i=0; i< __n; i++)
			{
				*(this->data() + i) = __c;
			}
			_p[__n]=0;
      }



      /**
       *  @brief  Destroy the string instance.
       */
      ~Fixbasic_string() 
      {  }

      /**
       *  @brief  Assign the value of @a str to this string.
       */
      Fixbasic_string&
      operator=(const Fixbasic_string& __str) 
      { 
		  _copy(__str.data(),__str.size()); 
		  return *this;
	  }

      /**
       *  @brief  Copy contents of @a s into this string.
       */
      Fixbasic_string&
      operator=(const _CharT* __s) 
      { 
		  _copy(__s, strlen(__s)); 
		  return *this;
	   }

      /**
       *  @brief  Set value to string of length 1.
       */
      Fixbasic_string&
      operator=(_CharT __c) 
      { 
			this->data()[0] = __c; 
			this->data()[1] = 0;
			_size=1;
			return *this;
      }

    public:

      ///  Returns the number of characters in the string, not including any
      ///  null-termination.
      size_type
      length() 
      { 
		  return size(); 
	  }


      /**
       *  Erases the string, making it empty.
       */
      void
      clear() 
      {
		  memset(this->data(), 0, this->size() * sizeof(_CharT) ) ; 
	   }

      /**
       *  Returns true if the %string is empty.  Equivalent to 
       *  <code>*this == ""</code>.
       */
      bool
      empty() 
      { 
		  return this->size() == 0; 
	  }

      
      _CharT operator[] (size_type __pos) const
      {
		assert(__pos <= size());
		return this->data()[__pos];
      }

      _CharT 
      at(size_type __n) const
      {
		if (__n >= this->size())
			throw std::runtime_error("basic_string::at");
		return data()[__n];
      }

      /**
       *  @brief  Provides access to the data contained in the %string.
       *  @param __n The index of the character to access.
       *  @return  Read/write reference to the character.
       *  @throw  std::out_of_range  If @a n is an invalid index.
       *
       *  This function provides for safer data access.  The parameter is
       *  first checked that it is in the range of the string.  The function
       *  throws out_of_range if the check fails.  Success results in
       *  unsharing the string.
       */
      _CharT&
      at(size_type __n)
      {
		if (__n >= size())
			throw std::runtime_error("basic_string::at");
		return data()[__n];
      }


      // Modifiers:
      /**
       *  @brief  Append a string to this string.
       *  @param __str  The string to append.
       *  @return  Reference to this string.
       */
      Fixbasic_string&
      operator+=(const Fixbasic_string& __str)
      { 
		  this->_append(__str.data()); 
		  return *this;
	  }

      /**
       *  @brief  Append a C string.
       */
      Fixbasic_string&
      operator+=(const _CharT* __s)
      { 
		  this->_append(__s); 
		  return *this;
	  }

      /**
       *  @brief  Append a character.
       */
      Fixbasic_string&
      operator+=(_CharT __c)
      { 
		this->_push_back(__c);
		return *this;
      }

      /**
       *  @brief  Append a string to this string.
       */
      Fixbasic_string&
      append(const Fixbasic_string& __str)
      { 
		  this->_append(__str.data()); 
		  return *this;
	  }

      /**
       *  @brief  Append a substring.
       */
      Fixbasic_string&
      append(const Fixbasic_string& __str, size_type __pos, size_type __n);

      /**
       *  @brief  Append a C substring.
       */
      Fixbasic_string&
      append(const _CharT* __s, size_type __n)
	  {
		 this->_append(__s , __n);
		 return *this;
	  }
		  

      /**
       *  @brief  Append a C string.
       */
      Fixbasic_string&
      append(const _CharT* __s)
      {
		 this->_append(__s );
		 return *this;
      }

      /**
       *  @brief  Append multiple characters.
       */
      Fixbasic_string&
      append(size_type __n, _CharT __c)
      { 
		  this->_append(__c, __n);
		  return *this ;
	  }



      /**
       *  @brief  Set value to contents of another string.
       */
      Fixbasic_string&
      assign(const Fixbasic_string& __str)
      { return *this ;}


      /**
       *  @brief  Set value to a substring of a string.
       */
      Fixbasic_string&
      assign(const Fixbasic_string& __str, size_type __pos, size_type __n)
      { return *this ;}

      /**
       *  @brief  Set value to a C substring.
       */
      Fixbasic_string&
      assign(const _CharT* __s, size_type __n)
      { return this ;}

      /**
       *  @brief  Set value to contents of a C string.
       */
      Fixbasic_string&
      assign(const _CharT* __s)
      { return *this ;}

      /**
       *  @brief  Set value to multiple characters.
       */
      Fixbasic_string&
      assign(size_type __n, _CharT __c)
      { return *this ;}


      Fixbasic_string&
      insert(size_type __pos1, const Fixbasic_string& __str)
      { return *this ;}

      Fixbasic_string&
      insert(size_type __pos1, const Fixbasic_string& __str,
	     size_type __pos2, size_type __n)
      { return *this ;}

      /**
       *  @brief  Insert a C substring.
      */
      Fixbasic_string&
      insert(size_type __pos, const _CharT* __s, size_type __n)
      { return *this ;}
	  

      /**
       *  @brief  Insert a C string.
      */
      Fixbasic_string&
      insert(size_type __pos, const _CharT* __s)
      {
		//__glibcxx_requires_string(__s);
		return this->insert(__pos, __s, strlen(__s));
      }

      /**
       *  @brief  Insert multiple characters.
      */
      Fixbasic_string&
      insert(size_type __pos, size_type __n, _CharT __c)
      { return *this ;}


      /**
       *  @brief  Remove characters.
      */
      Fixbasic_string&
      erase(size_type __pos = 0, size_type __n = _sizeT)
      { 
		return *this;
      }


      /**
       *  @brief  Replace characters with value from another string.
      */
      Fixbasic_string&
      replace(size_type __pos, size_type __n, const Fixbasic_string& __str)
      { return *this ;}

      /**
       *  @brief  Replace characters with value from another string.
      */
      Fixbasic_string&
      replace(size_type __pos1, size_type __n1, const Fixbasic_string& __str,
	      size_type __pos2, size_type __n2)
      { return *this ;}

      /**
       *  @brief  Replace characters with value of a C substring.
      */
      Fixbasic_string&
      replace(size_type __pos, size_type __n1, const _CharT* __s,
	      size_type __n2)
      {		return *this;    }

      /**
       *  @brief  Replace characters with value of a C string.
      */
      Fixbasic_string&
      replace(size_type __pos, size_type __n1, const _CharT* __s)
      {
	
		return this->replace(__pos, __n1, __s, strlen((char*)__s));
      }

      /**
       *  @brief  Replace characters with multiple characters.
      */
      Fixbasic_string&
      replace(size_type __pos, size_type __n1, size_type __n2, _CharT __c)
      { 
		return *this;
      }


 
    public:

      /**
       *  @brief  Copy substring into C string.
      */
      void
      copy(_CharT* __s, size_type __n ) const
	  {
		  this->_copy(__s, __n  );
	   }

      /**
       *  @brief  Swap contents with another string.
       *  @param __s  String to swap with.
       *
       *  Exchanges the contents of this string with that of @a __s in constant
       *  time.
      */
      void
      swap(Fixbasic_string& __s){}

      // String operations:
      /**
       *  @brief  Return const pointer to null-terminated contents.
       *
       *  This is a handle to internal data.  Do not modify or dire things may
       *  happen.
      */
      const _CharT*
      c_str() 
      { return data(); }


      size_type
      find(const _CharT* __s, size_type __pos, size_type __n) 
	  {return 0;}

      /**
       *  @brief  Find position of a string.
      */
      size_type
      find(const Fixbasic_string& __str, size_type __pos = 0) 
	  {return 0;}

      /**
       *  @brief  Find position of a C string.
      */
      size_type
      find(const _CharT* __s, size_type __pos = 0) const
	  {return 0;}

      /**
       *  @brief  Find position of a character.
      */
      size_type
      find(_CharT __c, size_type __pos = 0) 
	  {return 0;}

      /**
       *  @brief  Find last position of a string.
      */
      size_type
      rfind(const Fixbasic_string& __str, size_type __pos = _sizeT) 
	  {return 0;}

      /**
       *  @brief  Find last position of a C substring.
      */
      size_type
      rfind(const _CharT* __s, size_type __pos, size_type __n) const
	  {return 0;}

      /**
       *  @brief  Find last position of a C string.
      */
      size_type
      rfind(const _CharT* __s, size_type __pos = _sizeT) const
      {
		return this->rfind(__s, __pos, strlen(__s));
      }

      /**
       *  @brief  Find last position of a character.
       *
       *  Starting from @a __pos, searches backward for @a __c within
       *  this string.  If found, returns the index where it was
       *  found.  If not found, returns npos.
      */
      size_type
      rfind(_CharT __c, size_type __pos = _sizeT) 
      {
		return 0;
      }

      /**
       *  @brief  Find position of a character of string.
       *  Starting from @a __pos, searches forward for one of the
       *  characters of @a __str within this string.  If found,
       *  returns the index where it was found.  If not found, returns
       *  npos.
      */
      size_type
      find_first_of(const Fixbasic_string& __str, size_type __pos = 0) 
      { return this->find_first_of(__str.data(), __pos, __str.size()); }

      size_type
      find_last_of(const Fixbasic_string& __str, size_type __pos = _sizeT) const
      { return 0; }

      size_type
      find_first_not_of(const _CharT* __s, size_type __pos,
			size_type __n) const
      { return 0; }
			

      Fixbasic_string
      substr(size_type __pos = 0, size_type __n = 0) const
      { return *this;}

 
  };
  
typedef Fixbasic_string<char> fixedstring;

// true if the contents of the strings are equivalent, false otherwise
template<typename _CharT , int _sizeT = 255>
bool operator==( const Fixbasic_string<_CharT , _sizeT >& __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs)
{ return __lhs.compare(__rhs) == 0; }


template<typename _CharT , int _sizeT = 255>
bool operator==( const Fixbasic_string<_CharT , _sizeT >& __lhs, const _CharT *  __rhs)
{ return __lhs.compare(__rhs) == 0; }

template<typename _CharT , int _sizeT = 255>
bool operator==( const _CharT * __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs)
{ return __rhs.compare(__lhs) == 0; }



// true if the contents of the strings are not equivalent, false otherwise 
template<typename _CharT , int _sizeT = 255>
bool operator!=( const Fixbasic_string<_CharT , _sizeT >& __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs )
{ return __lhs.compare(__rhs) != 0; }

template<typename _CharT , int _sizeT = 255>
bool operator!=( const Fixbasic_string<_CharT , _sizeT >& __lhs, const _CharT *  __rhs)
{ return __lhs.compare(__rhs) != 0; }

template<typename _CharT , int _sizeT = 255>
bool operator!=( const _CharT * __lhs, Fixbasic_string<_CharT , _sizeT >& __rhs)
{ return __rhs.compare(__lhs) != 0; }



 
// true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise   
template<typename _CharT , int _sizeT = 255>
bool operator<( const Fixbasic_string<_CharT , _sizeT >& __lhs,  const Fixbasic_string<_CharT , _sizeT >& __rhs )
{ return __lhs.compare(__rhs) < 0; }

template<typename _CharT , int _sizeT = 255>
bool operator<( const Fixbasic_string<_CharT , _sizeT >& __lhs, const _CharT *  __rhs)
{ return __lhs.compare(__rhs) < 0; }

template<typename _CharT , int _sizeT = 255>
bool operator<( const _CharT * __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs)
{ return __rhs.compare(__lhs) > 0; }



// true if the contents of the lhs are lexicographically less than or equal the contents of rhs, false otherwise 
template<typename _CharT , int _sizeT = 255>
bool operator<=( const Fixbasic_string<_CharT , _sizeT >& __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs )
{ return __lhs.compare(__rhs) <= 0; }

template<typename _CharT , int _sizeT = 255>
bool operator<=( const  Fixbasic_string<_CharT , _sizeT >& __lhs, const _CharT *  __rhs)
{ return __lhs.compare(__rhs) <=0; }

template<typename _CharT , int _sizeT = 255>
bool operator<=( const _CharT * __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs)
{ return __rhs.compare(__lhs) >= 0; }


// true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise 
template<typename _CharT , int _sizeT = 255>
bool operator>( const Fixbasic_string<_CharT , _sizeT >& __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs )
{ return __lhs.compare(__rhs) > 0; }


template<typename _CharT , int _sizeT = 255>
bool operator>( const Fixbasic_string<_CharT , _sizeT >& __lhs, const _CharT *  __rhs)
{ return __lhs.compare(__rhs) > 0; }

template<typename _CharT , int _sizeT = 255>
bool operator>( const _CharT * __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs)
{ return __rhs.compare(__lhs) < 0; }



// true if the contents of the lhs are lexicographically greater than or equal the contents of rhs, false otherwise 
template<typename _CharT , int _sizeT = 255>
bool operator>=( const Fixbasic_string<_CharT , _sizeT >& __lhs, const Fixbasic_string<_CharT , _sizeT >& __rhs )
{ return __lhs.compare(__rhs) >= 0; }


template<typename _CharT , int _sizeT = 255>
bool operator>=( const Fixbasic_string<_CharT , _sizeT >& __lhs, const _CharT *  __rhs)
{ return __lhs.compare(__rhs) >=0; }

template<typename _CharT , int _sizeT = 255>
bool operator>=( const _CharT * __lhs, Fixbasic_string<_CharT , _sizeT >& __rhs)
{ return __rhs.compare(__lhs) <= 0; }


  
#endif