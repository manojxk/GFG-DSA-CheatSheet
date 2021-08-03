-- 1. 2nd Highest Salary 
select
    MAX(sal)
from
    emp
where
    sal not in (
        select
            MAX(sal)
        from
            emp
    );

-- 2. Department wise highest Salary Use only the column on which you are segregating and aggregate function
select
    MAX(sal),
    Department
from
    emp
from
    emp
group by
    Department;

-- Number of people in each dept
select
    count(*),
    Department
from
    emp
from
    emp
group by
    Department;

-- 3. Display Alternate Records
-- rownum is a pseudo column
select
    *
from
    (
        select
            empno,
            ename,
            sal,
            rownum rn
        from
            emp
        order BY
            rn
    )
where
    mod(rn, 2) != 0;

-- 4. Display Duplicate of a Column
select
    ename,
    count(*)
from
    emp
group BY
    ename
HAVING
    count(*) > 1;

-- 5. Pattern matching in SQL
-- Emp name starts with 'M'
select
    ename
from
    emp
where
    ename like 'M%';

-- Emp name ends with 'N'
select
    ename
from
    emp
where
    ename like '%N ';

-- Emp name having 'M'
select
    ename
from
    emp
where
    ename like '%N%';

-- Emp name NOT having 'M'
select
    ename
from
    emp
where
    ename not like '%N%';

-- 6. Pattern searching in SQL- 2
--emp name containing only four letters
select
    ename
from
    emp
where
    ename like '____';

--second letter L, 4th 'M'
select
    ename
from
    emp
where
    ename like '_L_M%';

--Emp joined in Dec
select
    hiredate,
    ename
from
    emp
where
    hiredate like '%DEC%';

-- 7. Display nth row in SQL
select
    *
from
    emp
where
    rownum <= n
minus
select
    *
from
    emp
where
    rownum <= n -1;

--2nd method
select
    *
from
    emp (
        select
            rownum r,
            emp.*
        from
            emp
    )
where
    r = n;

-- 8. union vs uninonall->include duplicates too
select
    city
from
    sample1
union
select
    city
from
    sample2;

-- Inner Join
select
    ename,
    sal,
    d.deptno
from
    emp e,
    dept d
where
    e.deptno = d.deptno;

-- sum of salaries in dept
select
    dname,
    sum(sal)
from
    emp e,
    dept d
where
    e.deptno = d.deptno
group by
    deptno;

-- 10. Self Join
--find the manager
select
    e1.ename "employes",
    e2.ename "manager"
from
    emp e1,
    emp e2
where
    e2.empno = e1.mgr;

-- 16. Nth highest salary