% fatos
progenitor(sara, isaque).
progenitor(abraao, isaque).
progenitor(abraao, ismael).
progenitor(isaque, esau).
progenitor(isaque, jaco).
progenitor(jaco, jose).

% regras
filho(Y, X) :- progenitor(X, Y).
avo(X,Y) :- progenitor(X, Z), progenitor(Z, Y).
ancestral(X, Z) :- progenitor(X, Z).
ancestral(X, Z) :- progenitor(X, Y), ancestral(Y, Z).