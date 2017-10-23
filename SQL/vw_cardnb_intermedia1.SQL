CREATE VIEW vw_cardnb_intermedia1 AS
SELECT
	(SELECT SUM(I.`amount`) AS `inventory_amnt` FROM `inventory` I INNER JOIN `item_db` IT ON IT.`id`=I.`nameid` AND IT.`type`=6) AS `inventory_amnt`
	,(SELECT COUNT(`id`) AS `inventory_slotted0` FROM `inventory` WHERE card0 IS NOT NULL AND card0 > 0 AND nameid NOT IN (7420)) AS `inventory_slotted0`
	,(SELECT COUNT(`id`) AS `inventory_slotted1` FROM `inventory` WHERE card1 IS NOT NULL AND card1 > 0 AND nameid NOT IN (7420)) AS `inventory_slotted1`
	,(SELECT COUNT(`id`) AS `inventory_slotted2` FROM `inventory` WHERE card2 IS NOT NULL AND card2 > 0 AND nameid NOT IN (7420)) AS `inventory_slotted2`
	,(SELECT COUNT(`id`) AS `inventory_slotted3` FROM `inventory` WHERE card3 IS NOT NULL AND card3 > 0 AND nameid NOT IN (7420)) AS `inventory_slotted3`
	,(SELECT COUNT(`id`) AS `storage_slotted0` FROM `storage` WHERE card0 IS NOT NULL AND card0 > 0 AND nameid NOT IN (7420)) AS `storage_slotted0`
	,(SELECT COUNT(`id`) AS `storage_slotted1` FROM `storage` WHERE card1 IS NOT NULL AND card1 > 0 AND nameid NOT IN (7420)) AS `storage_slotted1`
	,(SELECT COUNT(`id`) AS `storage_slotted2` FROM `storage` WHERE card2 IS NOT NULL AND card2 > 0 AND nameid NOT IN (7420)) AS `storage_slotted2`
	,(SELECT COUNT(`id`) AS `storage_slotted3` FROM `storage` WHERE card3 IS NOT NULL AND card3 > 0 AND nameid NOT IN (7420)) AS `storage_slotted3`
	,(SELECT SUM(S.`amount`) AS `storage_amnt` FROM `storage` S INNER JOIN `item_db` SIT ON SIT.`id`=S.`nameid` AND SIT.`type`=6) AS `storage_amnt`		
;
