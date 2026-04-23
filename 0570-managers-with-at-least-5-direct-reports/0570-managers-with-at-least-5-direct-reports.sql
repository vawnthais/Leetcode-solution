# Write your MySQL query statement below
select name 
from Employee E1
    left join (select managerId, count(*) as count_manager
                from Employee
                group by managerId)
                E2
            on E1.id = E2.managerId
where count_manager >= 5
