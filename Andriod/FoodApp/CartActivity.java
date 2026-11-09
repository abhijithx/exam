package com.example.foodapp;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.*;
import androidx.appcompat.app.AppCompatActivity;

public class CartActivity extends AppCompatActivity {

    TextView productDetails, total;
    Button buyNow;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cart);

        productDetails = findViewById(R.id.productDetails);
        total = findViewById(R.id.total);
        buyNow = findViewById(R.id.buyNow);

        int q1 = getIntent().getIntExtra("q1", 0);
        int q2 = getIntent().getIntExtra("q2", 0);

        int burgerTotal = q1 * 120;
        int pizzaTotal = q2 * 200;

        String details = "";

        if (q1 > 0) {
            details += "Burger x " + q1 + " = ₹" + burgerTotal + "\n\n";
        }

        if (q2 > 0) {
            details += "Pizza x " + q2 + " = ₹" + pizzaTotal;
        }

        productDetails.setText(details);

        int grandTotal = burgerTotal + pizzaTotal;

        total.setText("Total: ₹" + grandTotal);

        buyNow.setOnClickListener(v -> {

            Toast.makeText(
                    this,
                    "Purchase Successful!",
                    Toast.LENGTH_LONG
            ).show();

            SharedPreferences sp = getSharedPreferences("FoodHistory", MODE_PRIVATE);

            String oldHistory = sp.getString("history", "");

            String newOrder = "Burger: " + q1 +
                    "\nPizza: " + q2 +
                    "\nTotal: ₹" + grandTotal +
                    "\n-------------------\n";

            String updatedHistory = oldHistory + newOrder;

            SharedPreferences.Editor editor = sp.edit();

            editor.putString("history", updatedHistory);

            editor.apply();

            Toast.makeText(this, "Purchase Successful!", Toast.LENGTH_LONG).show();

            finish();
        });
    }
}