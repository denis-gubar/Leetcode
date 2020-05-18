SELECT id,
    SUM(CASE WHEN month = 'Jan' THEN revenue END) "Jan_Revenue",
    SUM(CASE WHEN month = 'Feb' THEN revenue END) "Feb_Revenue",
    SUM(CASE WHEN month = 'Mar' THEN revenue END) "Mar_Revenue",
    SUM(CASE WHEN month = 'Apr' THEN revenue END) "Apr_Revenue",
    SUM(CASE WHEN month = 'May' THEN revenue END) "May_Revenue",
    SUM(CASE WHEN month = 'Jun' THEN revenue END) "Jun_Revenue",
    SUM(CASE WHEN month = 'Jul' THEN revenue END) "Jul_Revenue",
    SUM(CASE WHEN month = 'Aug' THEN revenue END) "Aug_Revenue",
    SUM(CASE WHEN month = 'Sep' THEN revenue END) "Sep_Revenue",
    SUM(CASE WHEN month = 'Oct' THEN revenue END) "Oct_Revenue",
    SUM(CASE WHEN month = 'Nov' THEN revenue END) "Nov_Revenue",
    SUM(CASE WHEN month = 'Dec' THEN revenue END) "Dec_Revenue"
 FROM Department
GROUP BY id
