import java.util.Map;

/**
 * Maintain URLs visited in most recently visited order.
 */
public class RecentlyUsed {

    Map<String, ListNode> visitedURLs = new HashMap<>();
    ListNode dummyHead = new ListNode("dummy");

    public void addUrl(String url) {

        if (visitedURLs.containsKey(url)) {
            ListNode node = visitedURLs.get(url);
            ListNode prev = node.prev;
            ListNode next = node.next;

            prev.next = next;
            next.prev = prev;
            addToHead(node);

        } else {
            ListNode newNode = new ListNode(url);
            visitedURLs.put(url, newNode);
            addToHead(newNode);
        }

    }

    public void printVisitedUrls() {
        ListNode node = dummyHead.next;
        while (node != null) {
            System.out.println(node.url);
            node = node.next;
        }
    }

    private void addToHead(ListNode newNode) {
        ListNode next = dummyHead.next;
        dummyHead.next = newNode;
        newNode.prev = dummyHead;
        newNode.next = next;
        if (next != null) {
            next.prev = newNode;
        }
    }

    public static void main(String[] args) {
        RecentlyUsed recentlyUsed = new RecentlyUsed();
        recentlyUsed.addUrl("www.facebook.com");
        recentlyUsed.addUrl("www.google.com");
        recentlyUsed.addUrl("www.apple.com");
        System.out.println("Should print in order: apple, google, facebook");
        recentlyUsed.printVisitedUrls();
        recentlyUsed.addUrl("www.google.com");
        System.out.println("Should print in order: google, apple, facebook");
        recentlyUsed.printVisitedUrls();
    }

    static class ListNode {

        String url;
        ListNode next;
        ListNode prev;

        public ListNode(String url) {
            this.url = url;
        }
    }
}
