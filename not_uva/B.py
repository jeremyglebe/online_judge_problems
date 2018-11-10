#Things the keys contain
keys = {

  "G major": { 
    'A': True,
    'A#': False,
    'Bb': False,
    'B': True,
    'C': True,
    'C#': False,
    'Db': False,
    'D': True,
    'D#': False,
    'Eb': False,
    'E': True,
    'F': False,
    'F#': True,
    'Gb': False,
    'G': True,
    'G#': False,
    'Ab': False
  }
 ,
  "C major": { 
    'A': True,
    'A#': False,
    'Bb': False,
    'B': True,
    'C': True,
    'C#': False,
    'Db': False,
    'D': True,
    'D#': False,
    'Eb': False,
    'E': True,
    'F': True,
    'F#': False,
    'Gb': False,
    'G': True,
    'G#': False,
    'Ab': False
  }
 ,
  "Eb major": { 
    'A': False,
    'A#': False,
    'Bb': True,
    'B': False,
    'C': True,
    'C#': False,
    'Db': False,
    'D': True,
    'D#': False,
    'Eb': True,
    'E': False,
    'F': True,
    'F#': False,
    'Gb': False,
    'G': True,
    'G#': False,
    'Ab': True
  }
 ,
  "F# minor": { 
    'A': True,
    'A#': False,
    'Bb': False,
    'B': True,
    'C': False,
    'C#': True,
    'Db': False,
    'D': True,
    'D#': False,
    'Eb': False,
    'E': True,
    'F': False,
    'F#': True,
    'Gb': False,
    'G': False,
    'G#': True,
    'Ab': False
  }
 ,
  "G minor": {
    'A': True,
    'A#': False,
    'Bb': True,
    'B': False,
    'C': True,
    'C#': False,
    'Db': False,
    'D': True,
    'D#': False,
    'Eb': True,
    'E': False,
    'F': True,
    'F#': False,
    'Gb': False,
    'G': True,
    'G#': False,
    'Ab': False
  }

}

#Get pitch names
r_pitches = [
  ["A"],
  ["A#", "Bb"],
  ["B"],
  ["C"],
  ["C#", "Db"],
  ["D"],
  ["D#", "Eb"],
  ["E"],
  ["F"],
  ["F#", "Gb"],
  ["G"],
  ["G#", "Ab"]
]

#round
from math import floor, ceil
def round(n):
  c = ceil(n)
  f = floor(n)
  x = c - n
  y = n - f
  if y < x:
    n = f
  else:
    n = c
  return n

#Processing data starts here-ish
from math import log2

num_freq = int(input())

frequencies = []
key_tracker = {}
for key in keys:
  key_tracker[key] = keys[key]

for i in range(num_freq):
  freq = log2(float(input()) /440) * 12
  p_pitches = r_pitches[round(freq) % 12]
  for key in keys:
    okay = False
    for pitch in p_pitches:
      if keys[key][pitch]:
        okay = True
    if not okay:
      try:
        del key_tracker[key]
      except KeyError:
        continue
  frequencies.append(freq)

if len(key_tracker) == 1:
  mykey = ""
  for key in key_tracker:
    mykey = key
    print(key)
  for f in frequencies:
    possible_prints = r_pitches[round(f) % 12]
    for pri in possible_prints:
      try:
        if keys[mykey][pri]:
          print(pri)
      except KeyError:
        continue
else:
  print("cannot determine key")
