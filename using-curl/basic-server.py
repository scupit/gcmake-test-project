from http.server import HTTPServer, BaseHTTPRequestHandler

class MyRequestHandler(BaseHTTPRequestHandler):
  def do_GET(self):
    self.send_response(200)
    self.send_header("Content-type", "text/plain")
    self.end_headers()
    self.wfile.write("Nice, it's working!".encode("utf-8"))

hostName = "localhost"
port = 8080
  
if __name__ == "__main__":
  webServer = HTTPServer((hostName, port), MyRequestHandler)
  print(f"Server running at http://{hostName}:{port}")

  try:
    webServer.serve_forever()
  except KeyboardInterrupt:
    pass
  finally:
    webServer.server_close()
    print("Server closed")