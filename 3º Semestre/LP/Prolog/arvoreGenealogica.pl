%fatos ------------------------------------------
progenitor(pamela,sam).
progenitor(pamela,bob).
progenitor(tom,sam).
progenitor(tom,bob).
progenitor(tom,liz).
progenitor(bob,ana).
progenitor(bob,patricia).
progenitor(patricia,jim).

homem(tom).
homem(bob).
homem(sam).
homem(jim).

mulher(pamela).
mulher(liz).
mulher(ana).
mulher(patricia).


%regras 1 ---------------------------------------
pai(X,Y) :- homem(X), progenitor(X,Y).

mae(X,Y) :- mulher(X), progenitor(X,Y).

%regras 2 ---------------------------------------
neta(X,Y) :- mulher(X), progenitor(Z,X), progenitor(Y,Z).

irmao(X,Y) :- progenitor(Z,X), progenitor(Z,Y).

avo(X,Y) :- progenitor(X,Z), progenitor(Z,Y).

%regras 3 ---------------------------------------
ancestral_feminino(X,Y) :- mulher(X), progenitor(X,Y).
ancestral_feminino(X,Y) :- progenitor(Z,Y), ancestral_feminino(X,Z).

ancestral_masculino(X,Y) :- homem(X), progenitor(X,Y).
ancestral_masculino(X,Y) :- progenitor(Z,Y), ancestral_masculino(X,Z).