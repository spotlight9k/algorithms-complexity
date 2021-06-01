[![Code Size](https://img.shields.io/github/languages/code-size/spotlight9k/algorithms-complexity)]() [![Repo Size](https://img.shields.io/github/repo-size/spotlight9k/algorithms-complexity)]() [![open issues](https://img.shields.io/github/issues-raw/spotlight9k/algorithms-complexity)]() [![whatchers](https://img.shields.io/github/watchers/spotlight9k/algorithms-complexity?style=social)]() 

# Aims of the research:

The aim of this research is to compare estimate the time complexity of  different multiplication algorithms via experiments. 

There are 3 algorithms to compare:
 - Grade School Multiplication
 - Divide and Conquer approach and 
 - Karatsuba algorithm. 

# Problem steps:

**1.**  I have to create class of a large number **Num**, using vector or string, and implement functions and operators there.

**2.**  I have to create a class **Multiplicator**. The class allows calculating a product of two integer numbers by applying different multiplication algorithms.
   * We are allowed to use C++ built-in multiplication for doing one-digit multiplications (eg, 3 times 5) but not any other multiplication (eg, 23 times 55).
   * We are allowed to use C++ built-in addition (even of large numbers).
   
**3.**   Create a method in the **Multiplicator** that generates a random number of k-digits, where k is a parameter of the method.

**4.**   In **Multiplicator** class I need create auxiliary methods needed to implement the **Grade School multiplication algorithm**, the **Divide-and-Conquer multiplication algorithm** and the **Karatsuba algorithm**.

**5.**  Implement the **Grade School multiplication algorithm**, the **Divide-and-Conquer multiplication algorithm** and the **Karatsuba algorithm** asmethods of **Multiplicator**.

**6.**  Create a method that performs calculation of a series of numbers containing from **1 to k** digits by applying both algorithms. 

**7.**  Create a method that outputs the experimental results stored in the vector as a CSV file containing exactly 3 columns: size of input data and resulting time for all algorithms.

**8.**  Based on the produced file, line charts are drawn by using Python's Matplotlib

# Implementation:

**1.**  The first step is a creation of the **Num** class. And I decide to realize the big number via string.  Class **Num**: 
   * type of the variables
  ```sh
    typedef unsigned short Short;
    typedef unsigned int Byte;
    typedef std::pair<Num, Num> Halves;

    Short size;
    std::string base;
```
* constructors and destructor:
```sh
    Num();                                 
    ~Num() ;                              
    Num(Short length, Byte dig);        
    Num(std::string& str, Short k);             
```
* functions:
```sh
    Short getSize() const;
    Byte getDigit(Short k) const;
    void setDigit(Short k, Byte dig);
    Num createNumber(Short k);
    void delereZeros(Num&);
    Short getNumber();
    Halves getHalf(Short length) const;                 
    Num multiplyByPowerOfTen(Short length) const;           
```
* operators
```sh
    Num operator+(const Num& n2);               
    Num operator-(const Num& n2);                
    void operator=(const Num&);
    std::ostream& operator<<(std::ostream& s);  
```
**2.** Secondly, I have to create class **Multiplicator** with 3 subclasses for each algorithm. Also, virtual function **multiply** should be implemented here and each of the algorithm class. Class **Multiplicator**:
* type of the variables
```sh
    typedef unsigned short Short;
    typedef unsigned int Byte;
    typedef std::pair<Num, Num> Halves;
    typedef std::vector<Num> Nums; 
```
* constructors and destructor: 
```sh
    Multiplicator();
    ~Multiplicator();
```
* virtual function and function for add and substraction
```sh
    virtual Num multiply(const Num& n1, const Num& n2) = 0;

    static Byte baseAdd(Byte, Byte, Byte&); 
    static Byte baseSubstraction(Byte d1, Byte d2, Byte& carry);
```
**3.**  I have to create subclasses of **Multiplicator** which are the algorithms classes. Also virtual function **multiply** have to be implemented here. Class **gradeSchoolMultiplication:**
* Subclass of **Multiplicator**
```sh
class gradeSchoolMultiplication : public Multiplicator
```
* Constructor + multiply + destructor
```sh
    gradeSchoolMultiplication();

    Num multiply(const Num& n1, const Num& n2);

    ~gradeSchoolMultiplication();
```
Class **divideAndConquer:**
* Subclass of **Multiplicator**
```sh
class divideAndConquer : public Multiplicator
```
* Constructor + multiply + destructor
```sh
    divideAndConquer();

    Num multiply(const Num& n1, const Num& n2);

    ~divideAndConquer();
```
Class **karatsubaMultiplication:**
* Subclass of **Multiplicator**
```sh
class karatsubaMultiplication : public Multiplicator
```
* Constructor + multiply + destructor
```sh
    karatsubaMultiplication();

    Num multiply(const Num& n1, const Num& n2);

    ~karatsubaMultiplication();
```

Obviously, implementation of the function multiply depends on the algorithm. And all functions, operators and conrtusctors/destructor are implemented in the **.cpp** files.    
**4.**  I need a class which combine all these together and provide an experiment itself. Class **Experiment:**
* Constructor + destructor
```sh
    Experiment();
    ~Experiment();
```
* Function exp which provide an experiment from the beginning (get the **limit (k)**, **step(step)** and the **CSV** file to out), then it conduct an experiment with **3** algorithms, and finally output it into the file. 
```sh
void exp(Num::Short k, Num::Short step, std::ofstream& out);
```
**5.**  The main part, here program asks for the **input** and then call the 
function **exp**.
* 
```sh
    Num::Short k;
    Num::Short step;
    std::string s;

    std::cin>>k>>step>>s;
    std::ofstream out(s);

    Experiment experiment;
    experiment.exp(k,step, out);
```
