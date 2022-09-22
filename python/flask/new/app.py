from flask import Flask, render_template, request, redirect

app = Flask(__name__)

SPORTS = [
    "Rugby",
    "Football",
    "Hockey"
]

REGISTRANTS = {}

@app.route("/")
def index():
    return render_template("index.html")


@app.route("/register", methods=["POST"])
def register():
    sport = request.form.get("sport")
    name = request.form.get("name")

    #validate submition
    if not request.form.get("name") or sport not in SPORTS :
        return render_template("failure.html")

    REGISTRANTS[name] = sport

    #confirm registration
    return redirect("/registrants")



@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants = REGISTRANTS)