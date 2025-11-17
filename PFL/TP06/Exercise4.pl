% = vs no =

translate(Code, Meaning):-
    Code = 1,
    Meaning = 'Integer Overflow'.
translate(Code, Meaning):-
    Code = 2,
    Meaning = 'Division by zero'.
translate(Code, Meaning):-
    Code = 3,
    Meaning = 'ID Unknown'.

% code is much tighter

translate(1,'Integer Overflow').
translate(2,'Division by zero').
translate(_,'ID Unkown').