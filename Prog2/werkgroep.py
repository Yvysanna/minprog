from beatles import Beatles 

paul = Beatles("Paul", 1942)

# What does this print and why?
print(paul)

# Why does this print something else?
print(paul.name)

# What does come here?
print(paul.instruments)

# And now?
paul.add_instrument("Piano")
print(paul.instruments)

# And what if we repeat this step?