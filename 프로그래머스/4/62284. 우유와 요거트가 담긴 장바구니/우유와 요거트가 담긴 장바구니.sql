SELECT CART_ID
  FROM CART_PRODUCTS
 WHERE NAME IN ('Milk','Yogurt')
 group by CART_ID
 having count(distinct NAME) >= 2