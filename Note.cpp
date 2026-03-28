/*
  ShoppingCart cart; vs auto cart = new ShoppingCart();
     ShoppingCart cart;
     1. The "Stack" - Best Practice
     2. This is called Automatic Allocation
     3. Faster, Safe
     4. You have to use (.) in this

     auto cart = new ShoppingCart();
     1. This is called Dynamic Allocation
     2. Manual Cleanup
     3. Slower
     4. Use Case : You only use "new" if the object needs to live a very
        long time or if the object is so massive it won't fit on the stack
     5. You have to use (->) in this
*/
