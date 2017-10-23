/*
This is a script that retrieves a sorted list (top)
of characters that have the specified item.
*/

DELIMITER //
set @nameid = 601;


SELECT 
	c.account_id
	,c.name
	,inv.inventory_amnt
	,crt.cart_amnt
	,mail.mail_amnt
	,stor.storage_amnt
	,(ifnull(inv.inventory_amnt, 0) + ifnull(crt.cart_amnt, 0) + ifnull(mail.mail_amnt, 0) + ifnull(stor.storage_amnt, 0)) AS tot_amnt
FROM `char` c
LEFT JOIN (SELECT char_id, SUM(amount) AS inventory_amnt FROM inventory WHERE nameid=@nameid GROUP BY char_id) inv
	ON inv.char_id=c.char_id
LEFT JOIN (SELECT char_id, SUM(amount) AS cart_amnt FROM cart_inventory WHERE nameid=@nameid GROUP BY char_id) crt
	ON crt.char_id=c.char_id
LEFT JOIN (SELECT dest_id AS char_id, SUM(amount) AS mail_amnt FROM mail WHERE nameid=@nameid GROUP BY dest_id) mail
	ON mail.char_id=c.char_id
LEFT JOIN (SELECT account_id, SUM(amount) AS storage_amnt FROM storage WHERE nameid=@nameid GROUP BY account_id) stor
	ON stor.account_id=c.account_id
	
ORDER BY tot_amnt DESC;
	
//
DELIMITER ;
