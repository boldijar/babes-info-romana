SELECT	fac.IdFactura			AS 'IdFactura', 
		cl.Denumire				AS 'NumeClient',
		fac.NumarFactura		AS 'NumarFactura',
		fac.DataEmiteri			AS 'DataEmiterii',
		SUM(pf.Cantitate * pf.Pret)	AS PretTotal

FROM	Facturi AS fac
		INNER JOIN ProduseFacturi AS pf
			ON (fac.IdFactura = pf.IdFactura)
		INNER JOIN Produse AS prod
			ON (pf.IdProdus = prod.IdProdus)
		INNER JOIN Clienti AS cl
			ON (fac.IdClient = cl.IdClient)

WHERE	'Produs1' IN (
						SELECT	prod2.Denumire
						FROM	ProduseFacturi AS pf2
								INNER JOIN Produse AS prod2
									ON (pf2.IdProdus = prod2.IdProdus)
						WHERE	(pf2.IdFactura = pf.IdFactura)
						)

GROUP BY	fac.IdFactura,
			cl.Denumire,
			fac.NumarFactura,
			fac.DataEmiteri

HAVING SUM(pf.Cantitate * pf.Pret) > 300;