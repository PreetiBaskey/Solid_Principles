/*
  ShoppingCart cart; vs auto cart = new ShoppingCart();
     ShoppingCart cart;
     1. The "Stack" - Best Practice
     2. This is called Automatic Allocation
     3. Faster, Safe
     4. You have to use (.) in this

     auto cart = new ShoppingCart();
     1. The "Heap" - Dangerous
     2. This is called Dynamic Allocation
     3. Manual Cleanup
     4. Slower
     5. Use Case : You only use "new" if the object needs to live a very
        long time or if the object is so massive it won't fit on the stack
     6. You have to use (->) in this
*/

/*
  ShoppingCart cart;
  1. Location - Stored on the Stack
  2. Life - It dies the moment } of the function is reached
  3. The Problem - If you want to pass this cart to another part of a
     large app (like a Database or a different Screen), the "Stack" might
     clear it out before you're done. It is "bolted" to the function it 
     was created in

  auto cart = make_unique<ShoppingCart>();
  1. Location - Stored on the Heap
  2. Life - It lives as long as the unique_ptr exists. It's more "mobile"
  3. Why use it here(Single Responsibility Principle Followed code)?
     Ownership - It clearly says "This main function owns this cart"
     Safety - You get the benefits of a pointer (the arrow -> syntax)
               without the risk of a memory leak. If your program crashes
               or ends, unique_ptr cleans up the memory automatically.

  Which one should you use?
    1. Use ShoppingCart cart; if you are writing a quick, small script where
       the cart never leaves that one function.
    2. Use make_unique if you are building a real system (like you current 
       code - Single Responsibility Principle Followed code) where different
       classed (Printer, Storage, Database) all need to look at the same cart.

       Think of it this way:
       ShoppingCart cart is like a built-in car radio (stuck in the car).
       make_unique is like a high-end Bluetooth speaker (you can carry it
       around, but it still below to you).
*/
