# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
from(select distinct salary from Employee
Order by salary desc limit 1 offset 1) t;