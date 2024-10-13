#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <iostream>
#include "types.hpp"  

namespace Bank {

class Customer {
public:
    Customer(i32 id, const std::string& name)
        : m_customer_id(id), m_customer_name(name) {}
    
    i32 GetCustomerId() const {
        return m_customer_id;
    }
    
    std::string GetCustomerName() const {
        return m_customer_name;
    }
    
    void DisplayCustomerInfo() const {
        std::cout << "Customer ID: " << m_customer_id << std::endl;
        std::cout << "Customer Name: " << m_customer_name << std::endl;
    }
    
private:
    i32 m_customer_id;
    std::string m_customer_name;
};

} 

#endif 
