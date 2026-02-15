SELECT Department, Employee, Salary 
FROM
    (SELECT  d.name AS Department,
            e.name AS Employee,
            e.salary AS Salary,
            dense_rank() OVER(partition by e.departmentId order by e.salary DESC) AS rnk
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id) x
WHERE x.rnk < 4;